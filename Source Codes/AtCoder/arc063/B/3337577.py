#!/usr/bin/env python3

def main():
    n, t = map(int, input().split())
    an = list(map(int, input().split()))

    mi = [an[0]]
    for i in range(1, n):
        mi.append(min(mi[i - 1], an[i]))

    ma = 0
    num_ma = 0
    for i in range(1, n):
        be = an[i] - mi[i - 1]
        if be > ma:
            ma = be
            num_ma = 1
        elif be == ma:
            num_ma += 1
    print(num_ma)

main()