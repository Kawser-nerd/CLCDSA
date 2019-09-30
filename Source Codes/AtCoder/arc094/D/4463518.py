#!/usr/bin/env python3


M = 998244353

def powmod(a, x, m = M):
    y = 1
    while 0 < x:
        if x % 2 == 1:
            y *= a
            y %= m
        x //= 2
        a = a ** 2
        a %= m

    return y


def solve(s):
    n = len(s)

    nb = nc = 0
    ch = s[0]
    if ch == 'b':
        nb += 1
    elif ch == 'c':
        nc += 1
    sf = True
    tf = True
    left = ch
    for ch in s[1:]:
        if ch == 'b':
            nb += 1
        elif ch == 'c':
            nc += 1
        if ch == left:
            sf = False
        else:
            tf = False
        left = ch


    if tf:
        return 1
    if n == 3:
        if (nb + nc * 2) % 3:
            return 7 if sf else 6
        else:
            return 3
    if n % 3:
        return (powmod(3, n - 1) + M - powmod(2, n - 1) + (1 if sf else 0)) % M
    else:
        if (nb + nc * 2) % 3:
            return (powmod(3, n - 1) + M - (powmod(2, n - 1) - powmod(2, n // 3 - 1)) + (1 if sf else 0)) % M
        else:
            return (powmod(3, n - 1) + M - (powmod(2, n // 3) + 4 * powmod(8, n // 3 - 1)) + (1 if sf else 0)) % M

def main():
    s = input()

    print(solve(s))


if __name__ == '__main__':
    main()