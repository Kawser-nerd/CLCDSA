import sys
sys.setrecursionlimit(10 ** 9)
N, X = map(int, input().split())


def rec(a, b):
    a, b = min(a, b), max(a, b)
    if b % a == 0:
        return (2 * a) * (b // a) - a
    else:
        return (2 * a) * (b // a) + rec(a, b % a)


print(X + N - X + rec(X, N - X))