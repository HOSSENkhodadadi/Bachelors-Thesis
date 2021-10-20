# -*- coding: utf-8 -*-
"""
Created on Thu Jun 24 12:58:14 2021

@author: Hossein Khodadadi
"""

import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
import seaborn as sns
country = "Germany"
#country = 'US'

#Total COVID confirmed cases

# df_confirmed = pd.read_csv("https://raw.githubusercontent.com/CSSEGISandData/COVID-19/master/csse_covid_19_data/csse_covid_19_time_series/time_series_covid19_confirmed_global.csv")
df_confirmed = pd.read_csv(r'H:\main_desktop\final-project\Global_Mobility_Report.csv')
df = df_confirmed[df_confirmed["country_region"] == country]
df.to_csv(r'H:\main_desktop\final-project\data\mobilityInGermany.csv')

#x = df.iloc[0:467, 8:15]
