# -*- coding: utf-8 -*-
import numpy as np


def inpl(): return map(int, input().split())


N = int(input())
X = np.zeros((1, N), dtype=np.float64)
Y = np.zeros((1, N), dtype=np.float64)
C = np.zeros((1, N), dtype=np.float64)

for i in range(N):
    x, y, c = inpl()
    X[0][i] = x
    Y[0][i] = y
    C[0][i] = c


def check(X, Y, C, t):
    D = np.maximum(np.abs(X-X.T), np.abs(Y-Y.T)) - ((t/C) + (t/C).T)
    return np.all(D <= 0)


OK = 2*10**8
NG = 0

while abs(OK-NG) > 10**-4:
    m = (OK+NG)/2
    if check(X, Y, C, m):
        OK = m
    else:
        NG = m
print(OK)