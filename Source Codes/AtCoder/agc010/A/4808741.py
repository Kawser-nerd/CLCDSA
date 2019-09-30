import numpy as np
N = int(input())
A = np.array(list(map(int, input().split())))
if sum(A % 2 == 1) % 2 == 0:
    print('YES')
else:
    print('NO')