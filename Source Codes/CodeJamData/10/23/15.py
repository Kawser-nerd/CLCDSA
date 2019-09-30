#!/usr/bin/env python

from sys import stdin, stdout

# nCk == n choose k (mod 100003)
nCk = [[int()]*501 for i in range(501)]
for n in range(0, 501):
    nCk[n][0] = 1
    for k in range(1, n+1):
        nCk[n][k] = nCk[n][k-1] * (n+1-k) / k
for n in range(0, 501):
    for k in range(1, n+1):
        nCk[n][k] %= 100003

# dynamic programming: number of possibilities
# to get sets for n with m elements
Y = [[int()]*501 for i in range(501)]
y = [int()]*501
for i in range(2, 501):
    Y[i][1] = 1
    y[i] = 1
    for j in range(2, i):
        # rank(i) == j
        for k in range(1, j):
            # rank(j) == k
            # Y(j,k) possibilities for the subset of {2,...,j}
            # i-j-1 choose j-k-1 possibilities for the subset of {j+1,...,i-1}
            Y[i][j] += Y[j][k] * nCk[i-j-1][j-k-1]
        y[i] += Y[i][j]
    y[i] %= 100003

for x in range(1, int(stdin.readline())+1):
    n = int(stdin.readline())
    stdout.write('Case #%i: %i\n' % (x, y[n]))

