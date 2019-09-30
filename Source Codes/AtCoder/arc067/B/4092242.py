#!/usr/bin/env python3

def main():
    n, a, b = map(int, input().split())
    xn = list(map(int, input().split()))

    res = 0
    for i in range(1, n):
        res += min(b, (xn[i] - xn[i - 1]) * a)
    print(res)

main()