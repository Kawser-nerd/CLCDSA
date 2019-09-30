#!/usr/bin/env python3


def powmod(a, x, m):
    y = 1
    while 0 < x:
        if x % 2 == 1:
            y *= a
            y %= m
        x //= 2
        a = a ** 2
        a %= m

    return y


def modinv(a, m):
    return powmod(a, m - 2, m)


M = 10 ** 9 + 7


def solve(n, a, t):

    if t <= n:
        return a[n]

    fact = [1] * (n + 1)
    for i in range(2, n + 1):
        fact[i] = fact[i - 1] * i % M

    b = [0] * (n + 1)
    s = -1 if n % 2 == 1 else 1
    for i in range(n + 1):
        b[i] = s * fact[i] * fact[n - i] % M
        s = -s


    p = 1
    for i in range(n + 1):
        p *= t - i
        p %= M

    q = 0
    for i in range(n + 1):
        q += a[i] * modinv(b[i] * (t - i) % M, M) % M


    return p * q % M


def main():
    n = input()
    n = int(n)
    a = list(map(int, input().split()))
    t = input()
    t = int(t)

    print(solve(n, a, t))


if __name__ == '__main__':
    main()