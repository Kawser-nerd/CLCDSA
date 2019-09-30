import sys
sys.setrecursionlimit(100000)
import bisect
n=int(input())
data=[]
for i in range(n):
    data.append(tuple(map(int,input().split())))
a=[]
for x,y in sorted(data,key=lambda x:(x[1],-x[0])):
    a.append(x)

import bisect
LIS = [a[0]]
for i in range(len(a)):
    if a[i] > LIS[-1]:
        LIS.append(a[i])
    else:
        LIS[bisect.bisect_left(LIS, a[i])] = a[i]
print(len(LIS))