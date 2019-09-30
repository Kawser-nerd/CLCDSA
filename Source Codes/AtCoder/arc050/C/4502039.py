from fractions import gcd
from functools import reduce
from operator import add
A, B, mod = map(int, input().split())
g = gcd(A, B)


def matmul(a1, a2):
    return [[reduce(add, (n * _a2[k] % mod for n, _a2 in zip(_a1, a2))) for k in range(len(a2[0]))] for _a1 in a1]


def solve(x, count):
    a = [[1, 0], [0, 1]]
    _a = [[x, 1], [0, 1]]
    while count:
        if count & 1:
            a = matmul(a, _a)
        _a = matmul(_a, _a)
        count >>= 1

    return a[0][1]


print(solve(10, A) * solve(pow(10, g, mod), B//g) % mod)