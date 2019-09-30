# This Python 3 environment comes with many helpful analytics libraries installed
# It is defined by the kaggle/python docker image: https://github.com/kaggle/docker-python
# For example, here's several helpful packages to load in 

import numpy as np # linear algebra
#import pandas as pd # data processing, CSV file I/O (e.g. pd.read_csv)

# Input data files are available in the "../input/" directory.
# For example, running this (by clicking run or pressing Shift+Enter) will list the files in the input directory

import os
#print(os.listdir("../input"))

import sys
#def input():
#    return sys.stdin.readline()[:-1]
sys.setrecursionlimit(1000000)
'''
from operator import itemgetter
a = [(1, "c", 1), (1, "b", 3), (2, "a", 0), (1, "a", 2)]
print(sorted(a))  # 0 ???????????????????? 1 ??????????
print(sorted(a, key=itemgetter(0)))  # 0 ???????????
print(sorted(a, key=itemgetter(0, 2)))  # 0 ??? 2 ?????????
print(sorted(a, key=lambda x: x[0] * x[2]))  # 0 ????? * 2 ?????????
print(sorted(a, reverse=True))  # ??????
a.sort()  # ????????sorted() ?????
'''

test_data1 = '''\
8
6
3
1
2
7
4
8
5
'''

test_data2 = '''\
6
3
2
5
1
4
6
'''

test_data3 = '''\
4
1
3
2
4
'''
td_num=3

def GetTestData(index):
    if index==1:
        return test_data1
    if index==2:
        return test_data2
    if index==3:
        return test_data3
    
if False:
    with open("../test.txt", mode='w') as f:
        f.write(GetTestData(td_num))
    with open("../test.txt") as f:
        #print(f.readlines())
        #print(f.read())
        # Start Input code ---------------------------------------
        n=int(f.readline())
        p=[0]*n
        for i in range(n):
            p[i]=int(f.readline())
        # End Input code ---------------------------------------
else:
    n=int(input())
    p=[0]*n
    for i in range(n):
        p[i]=int(input())
    # End Input code ---------------------------------------

a=[0]*n
cnt=1
ans=0
for i in range(n):
    a[p[i]-1]=i
#print('n,p=',n,p,a)
for i in range(n):
    if i==0:
        pre=a[0]
    else:
        if a[i]>pre:
            cnt+=1
        else:
            ans=max(ans,cnt)
            cnt=1
    ans=max(ans,cnt)
    pre=a[i]
print(n-ans)