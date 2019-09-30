import numpy as np


N, Q = map(int, input().split())
ans = np.zeros(N, dtype = np.int64)
for i in range(Q):
    L, R, T = map(int,input().split())
    ans[L-1:R] = T

for i in ans:
    print(i)