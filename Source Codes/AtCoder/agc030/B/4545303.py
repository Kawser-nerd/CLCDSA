import numpy as np
import sys

L, N = map(int, input().split())
X = np.array([int(sys.stdin.readline()) for _ in range(N)])
X2 = L - X[::-1]
Y1 = np.concatenate(([X[0]], X[1:] - X[:-1], [L - X[-1]]))
Y2 = Y1[::-1]
Z = np.concatenate((np.arange(N, -1, -2), np.arange(N - 1, -1, -2)[::-1]))


def myfunc(n, x):
    return x[n + (N - n + 1)//2 - 1] - 2 * x[n - 1] - (L - x[N - (N - n + 1)//2])


len1 = np.dot(Z, Y1)
len2 = np.dot(Z, Y2)
x1 = X.tolist()
x2 = X2.tolist()
ans = max(len1, len2)
for n in range(1, (N + 1) // 2):
    len1 += myfunc(n, x1)
    len2 += myfunc(n, x2)
    ans = max(ans, len1, len2)

print(ans)