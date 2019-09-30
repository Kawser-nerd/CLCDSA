import sys
input = sys.stdin.readline

N = int(input())
L = []
for i in range(N):
    w, h =  (int(i) for i in input().split())
    L.append((w,-h))

L.sort()

import bisect

LIS = [-L[0][1]]
    
for i in range(1,N):
    h = - L[i][1]
    if LIS[-1] < h:
        LIS.append(h)
    else:
        LIS[bisect.bisect_left(LIS, h)] = h

print(len(LIS))