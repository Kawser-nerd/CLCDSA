#!/usr/bin/env python3
import collections
def solve(k):
    if k == 1:
        return 1, [ [ 1 ] ]
    n = (k + 3) // 4 * 2
    f = [ [ None ] * n for _ in range(n) ]
    for y in range(n):
        for x in range(n):
            f[y][x] = (y * n + (x - y) % n) % (2 * n) + 1
            if f[y][x] > n:
                if f[y][x] - n <= 2 * n - k:
                    f[y][x] -= n
                else:
                    f[y][x] -= 2 * n - k
    return n, f

if __name__ == '__main__':
    k = int(input())
    n, f = solve(k)
    print(n)
    for y in range(n):
        print(*f[y])