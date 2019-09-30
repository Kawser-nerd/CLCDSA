import numpy as np
C = np.array([list(input()) for i in range(2)])

C_r = np.array([['0']*3 for i in range(2)])
for i in range(2):
    for j in range(3):
        C_r[1-i, 2-j] = C[i, j]

if np.all(C==C_r):
    print('YES')
else:
    print('NO')