"""
Created on Thu Jun 10 18:58:37 2021

@author: Hossein Khodadadi
"""

import numpy as np
from keras.models import Sequential
from keras.layers import LSTM
from keras.layers import Dense, Dropout
import pandas as pd
from matplotlib import pyplot as plt
from sklearn.preprocessing import StandardScaler
import seaborn as sns
#from datetime import datetime

# df_confirmed = pd.read_csv(r'H:\main_desktop\final-project\Global_Mobility_Report.csv')
# # df_confirmed = pd.read_csv(r'H:\main_desktop\final-project\data\mobilityInGermany.csv')
# df = df_confirmed[df_confirmed["country_region"] == "Germany"]
# df.to_csv(r'H:\main_desktop\final-project\data\mobilityInGermany.csv')
# mobility_raw = df.iloc[0:467, 8:15]

# import training data-change the address based on your directroy
df = pd.read_csv(r'F://ترم ها/final-project/data/main_data.csv')

# import test data-change the address based on your directroy
df_test = pd.read_csv(r'F://ترم ها/final-project/data/test_data.csv')

df_test.dropna(subset = ["date"], inplace=True)
df_test = df_test.iloc[0:14,]


#Separate dates for future plotting
train_dates = pd.to_datetime(df['date'])

#Variables for training
cols = list(df)[1:9]

df_for_training = df[cols].astype(float)

# df_for_plot=df_for_training.tail(5000)
# df_for_plot.plot.line()

#LSTM uses sigmoid and tanh that are sensitive to magnitude so values need to be normalized
# normalize the dataset
scaler = StandardScaler()
scaler = scaler.fit(df_for_training)
df_for_training_scaled = scaler.transform(df_for_training)


#As required for LSTM networks, we require to reshape an input data into n_samples x timesteps x n_features. 
#In this example, the n_features is 2. We will make timesteps = 3. 
#With this, the resultant n_samples is 5 (as the input data has 9 rows).
trainX = []
trainY = []

n_future = 1   # Number of days we want to predict into the future
n_past = 5    # Number of past days we want to use to predict the future

for i in range(n_past, len(df_for_training_scaled) - n_future +1):
    trainX.append(df_for_training_scaled[i - n_past:i, 0:df_for_training.shape[1]])
    trainY.append(df_for_training_scaled[i + n_future - 1:i + n_future, 0])

trainX, trainY = np.array(trainX), np.array(trainY)

print('trainX shape == {}.'.format(trainX.shape))
print('trainY shape == {}.'.format(trainY.shape))


# define Autoencoder model

model = Sequential()
model.add(LSTM(64, activation='relu', input_shape=(trainX.shape[1], trainX.shape[2]), return_sequences=True))
model.add(LSTM(32, activation='relu', return_sequences=False))
# model.add(Dropout(0.2))
model.add(Dense(trainY.shape[1]))

model.compile(optimizer='adam', loss='mse')
model.summary()


import os
import tensorflow as tf
checkpoint_path = r"H:\main_desktop\final-project\keep_weights\main_one\2\cp.ckpt"
checkpoint_dir = os.path.dirname(checkpoint_path)

cp_callback = tf.keras.callbacks.ModelCheckpoint(filepath=checkpoint_path,
                                                 save_weights_only=True,
                                                 verbose=1)

# fit model
history = model.fit(trainX, trainY, epochs=50, batch_size=16, validation_split=0.0001, verbose=1,callbacks=[cp_callback])

# plt.plot(history.history['loss'], label='Training loss')
# plt.plot(history.history['val_loss'], label='Validation loss')
# plt.legend()

model.load_weights(checkpoint_path)
# loss, acc = model.evaluate(test_generator, verbose=2)






#Forecasting...
#Start with the last day in training date and predict future...
n_future=14  #Redefining n_future to extend prediction dates beyond original n_future dates...
forecast_period_dates = pd.date_range(list(train_dates)[-1], periods=n_future, freq='1d').tolist()

forecast = model.predict(trainX[-n_future:]) #forecast 

#Perform inverse transformation to rescale back to original range
#Since we used 5 variables for transform, the inverse expects same dimensions
#Therefore, let us copy our values 5 times and discard them after inverse transform
forecast_copies = np.repeat(forecast, df_for_training.shape[1], axis=-1)
y_pred_future = scaler.inverse_transform(forecast_copies)[:,0]


# Convert timestamp to date
forecast_dates = []
for time_i in forecast_period_dates:
    forecast_dates.append(time_i.date())
    
df_forecast = pd.DataFrame({'date':np.array(forecast_dates), 'new_cases':y_pred_future})
df_forecast['date']=pd.to_datetime(df_forecast['date'])


# original = df[['date', 'new_cases']]
# original['date']=pd.to_datetime(original['date'])
# original = original.loc[original['date'] >= '2021-5-10']

# sns.set(rc = {'figure.figsize':(15,8)})
# sns.lineplot(original['date'], original['new_cases'])
# sns.lineplot(df_forecast['date'], df_forecast['new_cases'])
# sns.lineplot(df_test['date'], df_forecast['new_cases'])


# df_final = pd.DataFrame(columns=["actual_confirmed","predicted"], index=df_forecast['date'])
# df_final['predicted'] = df_forecast['new_cases']
# df_final.loc[:,"actual_confirmed"] = df_test["new_cases"]
df_test.insert(2, "Prediction", df_forecast['new_cases'], True)
df_test['date']=pd.to_datetime(df_test['date'])
df_test.index = df_test['date']
df_test = df_test.drop(columns = "date")
#Plot

df_test.plot(title="Predictions for next 14 days , n_past = 5, epoch = 50, size =16, non dropout,  load valSplit 0.0001 best")

