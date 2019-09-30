import numpy as np

N, M = map(int, input().split())
A = []
for i in range(N):
    A.append(list(input()))
B = []
for i in range(M):
    B.append(list(input()))
A = np.array(A)
B = np.array(B)


flag = False
for i in range(N-M+1):
    for j in range(N-M+1):
        if np.all(A[i:i+M, j:j+M]==B):
            flag = True

if flag:
    print('Yes')
else:
    print('No')