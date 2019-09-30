#!/usr/bin/env python3


def solve(n, a, b):
    x = x0 = 10 ** 10
    for i in range(n):
        if b[i] < a[i]:
            x = min(x, b[i])

    if x == x0:
        return 0
    else:
        return sum(a) - x


def main():
    n = int(input())
    a = []
    b = []
    for _ in range(n):
        ai, bi = input().split()
        a.append(int(ai))
        b.append(int(bi))


    print(solve(n, a, b))


if __name__ == '__main__':
    main()