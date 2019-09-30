import numpy as np
import sys

n = int(input())
d = [int(input()) for i in range(n)]

#d = [int(input())]
#d.append(int(input()))

print(sum(d))
if sum(d) - np.max(d) < np.max(d):
    if n == 1:
        print(sum(d))
    if 1 < n:
        print(-sum(d) + 2*np.max(d))
else:
    print(0)