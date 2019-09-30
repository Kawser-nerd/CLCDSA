# -*- coding: utf-8 -*-
def inpl(): return list(map(int, input().split()))

def make(N):
    if N%2:
        L = [N + (N//2)**2 - n**2 + 2*n - 1 for n in range(1, N//2+2)]
        L = L[1::][::-1] + L
        return L
    else:
        L = [N + N*(N-2)//4 -n**2 + n for n in range(1, N//2+1)]
        L = L[::-1] + L
        return L

N, M = inpl()

X = inpl()
Y = inpl()

A = make(N-1)
B = make(M-1)

Sx = 0
Sy = 0

for i, a in enumerate(A):
    Sx += a * (X[i+1] - X[i])

for j, b in enumerate(B):
    Sy += b * (Y[j+1] - Y[j])

print((Sx*Sy)%(10**9 + 7))