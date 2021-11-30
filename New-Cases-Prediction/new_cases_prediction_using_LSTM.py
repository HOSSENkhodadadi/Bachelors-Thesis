"""
Created on Thu Jun 10 18:58:37 2021
@author: Hossein Khodadadi

"""
# the model used in this projec is going to work on 
# sequences like number of Covid-19 infected people
from keras.models import Sequential

# Matplotlib is a comprehensive library for creating static,
# animated, and interactive visualizations in Python,see: https://matplotlib.org/
from matplotlib import pyplot as plt

# pandas is a library that offers data structures
# and operations for manipulating numerical tables and time series
import pandas as pd

# import fundamental package for scientific computing in Python
import numpy as np

# import LSTM from keras library
from keras.layers import LSTM

# add Dense to optimize the result and dropout to eliminate overfit
from keras.layers import Dense, Dropout

# Standard Scaler for normalizing the time series
from sklearn.preprocessing import StandardScaler

# Seaborn is a Python data visualization library
import seaborn as sns

# import training data-change the address based on your directroy
df = pd.read_csv(r'F://ترم ها/final-project/data/main_data.csv')

# import test data-change the address based on your directroy
df_test = pd.read_csv(r'F://ترم ها/final-project/data/test_data.csv')

# time series autocorrelation is important so neglect the date!
df_test.dropna(subset = ["date"], inplace=True)

# keep the last 14 entry for final evaluation of Neural Network
df_test = df_test.iloc[0:14,]


# Separate dates for future plotting
train_dates = pd.to_datetime(df['date'])

# Keep the necessary columns for training (neglect uncorrelated columns)
cols = list(df)[1:9]

# Convert data type to float to increase the accuracy in calculation.
df_for_training = df[cols].astype(float)

# df_for_plot=df_for_training.tail(5000)
# df_for_plot.plot.line()

#LSTM uses sigmoid and tanh that are sensitive to magnitude so values need to be normalized
# normalize the dataset using StandardScaler
scaler = StandardScaler()
scaler = scaler.fit(df_for_training)
df_for_training_scaled = scaler.transform(df_for_training)


#As required for LSTM networks, we require to reshape an input data into n_samples x timesteps x n_features. 
#In this example, the n_features is 1. We will make timesteps = 5. 
#With this, the resultant n_samples is 5 (as the input data has 9 rows).
trainX = []
trainY = []

# and important part of project is to optimize these two parameters
n_future = 1   # Number of days we want to predict into the future
n_past = 5    # Number of past days we want to use to predict the future

# slice the data and prepare it for feeding the Neural Network
# look at page 34 in my thesis report: predicting Covid-19 using LSTM ...
for i in range(n_past, len(df_for_training_scaled) - n_future +1):
    trainX.append(df_for_training_scaled[i - n_past:i, 0:df_for_training.shape[1]])
    trainY.append(df_for_training_scaled[i + n_future - 1:i + n_future, 0])
    
# preprocessing for feeding the data to network
trainX, trainY = np.array(trainX), np.array(trainY)

print('trainX shape == {}.'.format(trainX.shape))
print('trainY shape == {}.'.format(trainY.shape))


# define Autoencoder model, Optimize number of layers, neurons, type of layers
model = Sequential()
model.add(LSTM(64, activation='relu', input_shape=(trainX.shape[1], trainX.shape[2]), return_sequences=True))
model.add(LSTM(32, activation='relu', return_sequences=False))
# model.add(Dropout(0.2))
model.add(Dense(trainY.shape[1]))
# the best optimizer for this project was adam
# MSE: mean squared error :)
model.compile(optimizer='adam', loss='mse')
model.summary()

# TensorFlow is an open source library for numerical computation
# and large-scale machine learning
import tensorflow as tf

# os is necessary for passing the Neural Net parameters to an Address and save them for later use.
import os
checkpoint_path = r"H:\main_desktop\final-project\keep_weights\main_one\2\cp.ckpt"
checkpoint_dir = os.path.dirname(checkpoint_path)

# after fitting the model save the weights in this directory
cp_callback = tf.keras.callbacks.ModelCheckpoint(filepath=checkpoint_path,
                                                 save_weights_only=True,
                                                 verbose=1)

# NOW, fit the model
history = model.fit(trainX, trainY, epochs=50, batch_size=16, validation_split=0.0001, verbose=1,callbacks=[cp_callback])

# evalute the loss and val_loss
# plt.plot(history.history['loss'], label='Training loss')
# plt.plot(history.history['val_loss'], label='Validation loss')
# plt.legend()

# load the weights from previous RUN
# model.load_weights(checkpoint_path)
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

# put the predicted and real data together so that we can compare them.   
df_test.insert(2, "Prediction", df_forecast['new_cases'], True)
df_test['date']=pd.to_datetime(df_test['date'])
df_test.index = df_test['date']
df_test = df_test.drop(columns = "date")

#Plot
df_test.plot(title="Predictions for next 14 days , n_past = 5, epoch = 50, size =16, non dropout,  load valSplit 0.0001 best")

