import sys
from collections import defaultdict

# sys.stdin = open('e1.in')


def read_int_list():
    return list(map(int, input().split()))


def read_int():
    return int(input())


def read_str_list():
    return input().split()


def read_str():
    return input()


def gcd(a, b):
    if b == 0:
        return a
    return gcd(b, a % b)


def solve():
    def collinear(x0, y0, x1, y1):
        return x0 * y1 == x1 * y0

    def aligned(i, j, k):
        return collinear(x[j] - x[i], y[j] - y[i], x[k] - x[i], y[k] - y[i])

    n = read_int()
    mod = 998244353
    res = pow(2, n, mod) - n - 1
    x, y = zip(*[read_int_list() for i in range(n)])
    lines = defaultdict(set)
    for i in range(n):
        for j in range(i + 1, n):
            a = y[i] - y[j]
            b = x[j] - x[i]
            g = gcd(a, b)
            a //= g
            b //= g
            if a < 0 or (a == 0 and b < 0):
                a, b = -a, -b
            c = -(a * x[i] + b * y[i])
            lines[(a, b, c)].add(i)
            lines[(a, b, c)].add(j)
    for k, v in lines.items():
        m = len(v)
        res -= pow(2, m, mod) - m - 1
    res %= mod
    return res


def main():
    res = solve()
    print(res)


if __name__ == '__main__':
    main()