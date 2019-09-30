# D
import numpy as np
N = int(input())
A = np.array([list(map(int, input().split())) for _ in range(N)], dtype=int)

res = A.sum() // 2

A_ = A.copy()

# forbid self loop
for i in range(N):
    A_[i, i] = 1000000001


A3 = np.zeros((N, N, N), dtype=int)
for i in range(N):
    A3[i, :, :] += A_
for j in range(N):
    A3[:, :, j] += A_
    
A3_min = A3.min(axis=1)

for i in range(N-1):
    for j in range(i+1, N):
        if A3_min[i, j] < A[i, j]:
            res = -1
        elif A3_min[i, j] == A[i, j]:
            res -= A[i, j]
        
        
if res < 0:
    print(-1)
else:
    print(res)