#!/usr/bin/env python

import sys
input = sys.stdin

def solve(a, L):
    aux = sorted(a, reverse=True)
    return sum(aux[:L]) + sum(aux[L:]) * 2

def main():
    T = int(input.readline())
    for test in range(1, T + 1):
        test_case = map(int, input.readline().split())
        L, t, N, C = test_case[:4]
        a = test_case[4:]

        while len(a) < N:
            a.append(a[len(a) % C])

        if L == 0:
            print "Case #%d: %d" % (test, sum(a) * 2)
            continue

        cur_sum = 0
        pos = 0
        while cur_sum <= t and pos < N:
            cur_sum += a[pos] * 2
            pos += 1

        pos -= 1
        cur_sum -= a[pos] * 2
        # Case 1: Build a booster at pos
        length1 = cur_sum + (t - cur_sum) + \
            (a[pos] - (t - cur_sum) / 2) + \
            solve(a[(pos + 1):], L - 1)
        # Case 2: Do not build a booster at pos
        length2 = cur_sum + a[pos] * 2 + solve(a[pos + 1:], L)

        print "Case #%d: %d" % (test, min(length1, length2))

if __name__ == '__main__':
    main()
