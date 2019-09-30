#f[n][k] = c[n-k-1][k-r-1]*f[k][r]

import sys

N = 500
P = 100003

c = [[0] * (N+1) for i in range(N+1)]
f = [[0] * (N+1) for i in range(N+1)]
s = [0] * (N+1)
for i in range(N+1):
    c[i][0] = c[i][i] = 1
    for j in range(1,i):
        c[i][j] = c[i-1][j] + c[i-1][j-1]
        if c[i][j] >= P:
            c[i][j] -= P
for i in range(2,N+1):
    s[i] = f[i][1] = 1
    for j in range(2,i):
        f[i][j] = 0
        for k in range(1,j):
            f[i][j] += c[i-j-1][j-k-1]*f[j][k]
            f[i][j] %= P
        s[i] += f[i][j]
        s[i] %= P

t = int(sys.stdin.readline())
for _ in range(1,t+1):
    n = int(sys.stdin.readline())
    print 'Case #%d: %d' % (_, s[n])
