import numpy as np

H, W = map(int, input().split())
A = np.array([list(input()) for i in range(H)])

mask = A=='.'

row_idx = np.logical_not(np.all(mask, axis=1))
col_idx = np.logical_not(np.all(mask, axis=0))

for a in A[row_idx][:, col_idx]:
    print(''.join(list(a)))