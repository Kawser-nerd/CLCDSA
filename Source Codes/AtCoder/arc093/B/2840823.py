import string
import re
import datetime
import calendar
import collections
import heapq
import bisect
import array

import numpy as np

a, b = map(int,input().split())

ans = np.empty((100, 100), dtype=int)

x, y = ans.shape

for i in range(x):
    for j in range(y):
        if j == 0:
            ans[i,j] = 1
        elif j == y-1:
            ans[i,j] = 0
        elif (i % 4) == 0 or (i % 4) == 1:
            ans[i,j] = 1
        else:
            ans[i,j] = 0
def cut_b():
    itr = 1
    for i in range(2, x, 4):
        for j in range(2, y//2, 2):
            yield itr
            ans[i,j] = ans[i+1,j] = 1
            itr+=1

def cut_w():
    itr = 1
    for i in range(0, x, 4):
        for j in range(-3, -y//2, -2):
            yield itr
            ans[i,j] = ans[i+1,j] = 0
            itr+=1

for i in cut_b():
    if i == a:
        break
for i in cut_w():
    if i == b:
        break
print(100, 100)
for i in range(x):
    for j in range(y):
        if ans[i,j] == 0:
            print('.', end="")
        else:
            print('#', end="")
    print()