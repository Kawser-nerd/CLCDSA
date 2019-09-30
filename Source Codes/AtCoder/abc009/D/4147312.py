from functools import reduce
from operator import xor

def reads():
    return [int(x) for x in input().split()]

def powmod(u, x, n):
    y = u
    while n > 0:
        if n & 1 == 1:
            y = mul(y, x)
        x = mul(x, x)
        n >>= 1
    return y

def xsum(xs):
    return reduce(xor, xs)

ONE = (1 << 32) - 1

def mul(xs, ys):
    zs = [0] * W
    for i in range(W):
        for j in range(i+1):
            zs[i] ^= xs[j] & ys[i-j]
    for i in range(W-1, K-1, -1):
        for j in range(K+1):
            zs[i-K+j] ^= zs[i] & h[j]
    return zs

K, M = reads()
A = reads()
C = reads()

W = 2 * K + 1
u = [ONE] + [0] * (W - 1)
x = [0, ONE] + [0] * (W  - 2)
C.reverse()
h = C + [ONE]
f = powmod(u, x, M-1)

print(xsum(A[i] & f[i]for i in range(K)))