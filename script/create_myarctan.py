# -*- coding: utf-8 -*-
"""
Created on Thu Mar 21 15:08:03 2019

@author: zhuji
"""

import numpy as np
N = 16
myarctan= np.zeros(N)

with open('myarctan.h', 'w') as f:
    for i in range(N):
        myarctan[i] = np.arctan(2**(-i))
        f.write('{:.7f}'.format(myarctan[i]))
        if(i == N-1):
            f.write(' ')
        else:
            f.write(',')
            f.write('\n')
            