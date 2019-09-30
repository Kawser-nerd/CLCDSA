#!/usr/bin/env python3


def solve(n, p, c):

    d = [1] * n
    b = [0] * n

    for i in range(n - 1, -1, -1):
        if 0 <= p[i]:
            d[p[i]] += d[i]
        if len(c[i]):
            m = n - d[i] if i != 0 else 0
            for j in c[i]:
                m = max(m, d[j])
            b[i] = m
        else:
            b[i] = n - 1

    for i in range(n):
        print(b[i])


def main():
    n = input()
    n = int(n)
    p = [-1] * n
    c = [[] for _ in range(n)]
    for i in range(1, n):
        pi = input()
        pi = int(pi)
        p[i] = pi
        c[pi].append(i)


    solve(n, p, c)


if __name__ == '__main__':
    main()