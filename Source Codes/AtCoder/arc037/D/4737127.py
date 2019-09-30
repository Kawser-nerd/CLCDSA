#!/usr/bin/env python3

M = 10 ** 9 + 7


def solve(l):
    a = 1
    b = 2
    c = 1
    while 0 < l:
        a = (3 * a + b ** 3) % M
        nb = b ** 2 * (2 * c + 1) % M
        r = b * c ** 2 % M
        nb += M - r
        nb %= M
        nc = (b ** 2 + 2 * b * c ** 2) % M
        r = c ** 3  % M
        nc += M - r
        nc %= M
        b = nb
        c = nc
        l -= 1

    return a


def main():
    l = input()
    l = int(l)

    print(solve(l))


if __name__ == '__main__':
    main()