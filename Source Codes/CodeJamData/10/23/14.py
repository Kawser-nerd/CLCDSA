#!/usr/bin/env python
import fileinput

memo = {}

def f(n, m):
    if n < 0: return 0
    if n == 0: return 1
    if n in memo and m in memo[n]: return memo[n][m]
    s = 0
    for i in range(1, m+1):
        s += f(n-i, m)
    if n not in memo: memo[n] = {}
    memo[n][m] = s
    return s

def a079500(n):
    s = 0
    for i in range(0, n+1):
        s += f(i, n-i)
    return s

def main():
    reader = fileinput.input()
    trials = int(reader.next())
    for t in range(1, trials+1):
        result = trial(reader)
        print "Case #%d: %s" % (t, result)

def trial(reader):
    n = int(reader.next())
    return a079500(n - 1) % 100003

main()
