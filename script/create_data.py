# -*- coding: utf-8 -*-
"""
Created on Thu Mar 21 15:48:12 2019

@author: zhuji
"""

import numpy as np

N = 629
def write_data(file_name, file_data):
    with open(file_name, 'w') as f:
        for i in range(N):
            f.write('{:f}'.format(file_data[i]))
            f.write('\n')
        
myalpha = np.zeros(N)
mysin = np.zeros(N)
mycos = np.zeros(N)
for i in range(N):
    myalpha[i] = round((2*np.pi*float(i))/float(N)-np.pi,5);
    mysin[i] = round(np.sin(myalpha[i]),8)
    mycos[i] = round(np.cos(myalpha[i]),8)

write_data("myalpha.dat", myalpha)
write_data("mysin.dat", mysin)
write_data("mycos.dat", mycos)
