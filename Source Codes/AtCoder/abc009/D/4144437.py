from functools import reduce
from operator import xor

def reads():
    return [int(x) for x in input().split()]

def powmod(u, x, n, q):
    y = u
    while n > 0:
        if n & 1 == 1:
            y = y * x % q
        x = x * x % q
        n >>= 1
    return y

def xsum(xs):
    return reduce(xor, xs)

ONE = (1 << 32) - 1

class poly:
    def __init__(self, coef):
        self.coef = coef
    
    def dim(self):
        return len(self.coef) - 1

    def body(self):
        return self.coef, self.dim()
    
    def __mul__(self, other):
        xs, n = self.body()
        ys, m = other.body()
        l = n + m
        zs = [0] * (l + 1)
        for i in range(n+1):
            for j in range(m+1):
                zs[i+j] ^= xs[i] & ys[j]
        return poly(zs)

    def __mod__(self, other):
        xs, n = self.body()
        ys, m = other.body()
        assert m >= 0 and ys[m] == ONE
        zs = list(xs)
        for i in range(n, m-1, -1):
            for j in range(m+1):
                zs[i-m+j] ^= zs[i] & ys[j]
        l = next((i for i in range(n, -1, -1) if zs[i] != 0), 0)
        return poly(zs[:l+1])

K, M = reads()
A = reads()
C = reads()

u = poly([ONE])
x = poly([0, ONE])
h = poly(list(reversed(C)) + [ONE])
f = powmod(u, x, M-1, h)

print(xsum(A[i] & f.coef[i]for i in range(len(f.coef))))