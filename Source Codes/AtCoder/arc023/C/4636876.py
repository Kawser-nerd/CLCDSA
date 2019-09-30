#!/usr/bin/env python3

M = 10 ** 9 + 7

inv = [1] * (2020 + 1)
for i in range(2, 2020 + 1):
    inv[i] = inv[M % i] * (M - M // i) % M

def calc(n, k):

    r = 0
    c = 1
    c2 = 1
    for i in range(1, k + 1):
        c *= n + 1 - i
        c %= M
        c *= inv[i]
        c %= M
        if 1 < i:
            c2 *= k + 1 - i
            c2 %= M
            c2 *= inv[i - 1]
            c2 %= M
        r += c * c2
        r %= M

    return r


def solve(n, a):

    ans = 1
    c = 0
    for ai in a:
        if ai == -1:
            c += 1
        else:
            if 0 < c:
                ans *= calc(ai - p + 1, c)
                ans %= M
                c = 0
            p = ai

    return ans

def main():
    n = input()
    n = int(n)
    a = list(map(int, input().split()))

    print(solve(n, a))


if __name__ == '__main__':
    main()