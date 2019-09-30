from functools import reduce

def exp_mod(a, n, m):
    r = 1
    while n:
        if n & 1: r = r * a % m
        a = a * a % m
        n >>= 1
    return r

m = int(1e9 + 7)
n = int(input())
k = int(input())

a = reduce(lambda a, b: a * b % m, [i for i in range(n, n + k)], 1)
b = reduce(lambda a, b: a * b % m, [i for i in range(1, k + 1)], 1)

print(a * exp_mod(b, m - 2, m) % m)