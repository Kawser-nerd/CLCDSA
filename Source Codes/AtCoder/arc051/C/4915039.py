#!/usr/bin/env python3
import math
import heapq


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


M = 10 ** 9 + 7

def solve(n, a, b, aa):

    if n == 1:
        r = (aa[0] * powmod(a, b, M)) % M
        print(r)
        return


    aa.sort()
    if a == 1:
        for r in aa:
            print(r)
        return

    c = 0
    if n * 30 <= b:
        c = (b - n * 30) // n
        b -= c * n

    x0 = powmod(a, c, M)
    pa = [1] * (n * 30 + 1)
    x = 1
    for i in range(n * 30 + 1):
        pa[i] = x
        x *= a
        x %= M

    ca = [0] * n
    la = []
    for x in aa:
        la.append(math.log(x, a))

    q = []
    for i in range(n):
        heapq.heappush(q, (la[i], i))

    for i in range(b):
        x, j = heapq.heappop(q)
        ca[j] += 1
        x += 1
        heapq.heappush(q, (x, j))

    for i in range(n):
        _, j = heapq.heappop(q)
        r = (aa[j] * x0) % M
        r *= pa[ca[j]]
        r %= M
        print(r)


def main():
    n, a, b = input().split()
    n = int(n)
    a = int(a)
    b = int(b)
    aa = list(map(int, input().split()))

    solve(n, a, b, aa)

if __name__ == '__main__':
    main()