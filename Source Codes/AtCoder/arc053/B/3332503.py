#!/usr/bin/env python3

def main():
    s = input()
    n = len(s)
    di = {}
    for c in s:
        if c not in di:
            di[c] = 0
        di[c] += 1

    n_even = 0
    odds = []
    for c in di:
        if di[c] % 2 == 0:
            n_even += di[c]
        else:
            odds.append(di[c])

    if len(odds) == 0:
        print(n_even)
    else:
        k = len(odds)
        print(2 * ((n - k) // (2 * k)) + 1)

main()