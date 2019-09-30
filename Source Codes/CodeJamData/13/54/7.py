#!/usr/bin/python3

import sys

T = int(sys.stdin.readline())

def pay(gondola):
    n = len(gondola)
    if gondola.count(".") == 0:
        return 0
    if gondola in memo:
        return memo[gondola]
    g2 = gondola + gondola
    ans = 0.0
    for i in range(n):
        if gondola[i] == '.':
            ans += n + pay(gondola[:i] + "X" + gondola[i+1:])
        else:
            # gondola[i] == 'X'
            j = i
            wait = 0
            while g2[j] == 'X':
                wait += 1
                j += 1
            j %= n
            ans += (n-wait) + pay(gondola[:j] + "X" + gondola[j+1:])
    memo[gondola] = ans/n
    return memo[gondola]

for test_case in range(1, T+1):
    gondola = sys.stdin.readline().strip()
    memo = {}
    print("Case #{0}: {1}".format(test_case, pay(gondola)))
