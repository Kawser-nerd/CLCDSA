# -*- coding: utf-8 -*-
"""
Created on Sun Jan 20 15:45:54 2019
ABC039D
@author: maezawa
"""

import itertools as itr
import copy

h, w = list(map(int, input().split()))
a = [['_']*(w+2) for _ in range(h+2)]
for i in range(1, h+1):
    raw = list(input())
    a[i][1:w+1] = raw

b = copy.deepcopy(a)

#print(*a, sep='\n')
    
def areblacks(arr, i0, j0):
    for i in range(i0-1,i0+2):
        for j in range(j0-1,j0+2):
            if arr[i][j] == '#':
                return True
    return False

def arewhites(arr, i0, j0):
    for i in range(i0-1,i0+2):
        for j in range(j0-1,j0+2):
            if arr[i][j] == '.':
                return True
    return False
            
for i, j in itr.product(range(1, h+1),range(1, w+1)):
    if a[i][j] == '.':
        continue
    if arewhites(a, i, j):
        b[i][j] = '.'
        #print(i,j,b[i][j])
        
c = copy.deepcopy(b)
for i, j in itr.product(range(1, h+1),range(1, w+1)):
    if b[i][j] == '#':
        continue
    if areblacks(b, i, j):
        c[i][j] = '#'  

if a == c:
    print('possible')
    for i in range(1, h+1):
        print(''.join(b[i][1:w+1]))
else:
    print('impossible')