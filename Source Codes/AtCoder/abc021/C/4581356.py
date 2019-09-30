import numpy as np
n = int(input())
a, b = map(int, input().split())
m = int(input())
A = [[0 for _ in range(n+1)] for _ in range(n+1)]
for _ in range(m):
    x, y = map(int, input().split())
    A[x][y] = 1
    A[y][x] = 1
A = np.matrix(A)
B = A.copy()
while B[a, b] == 0:
    B *= A
print(B[a, b]%(10**9+7))