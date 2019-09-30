import sys
import itertools
import math
import collections
import functools

sys.setrecursionlimit(10000)

def inputInts():
    return map(int, raw_input().split())

def solve(C, V, D, coins):
    # First, we remove all coins that are too big
    while D > 0 and coins[D-1] > V:
        coins.pop()
        D -= 1

    res = 0
    nextCoinIdx = 0
    highestReached = 0
    while highestReached < V:
        if nextCoinIdx < D and highestReached >= coins[nextCoinIdx] - 1:
            highestReached += C * coins[nextCoinIdx]
            nextCoinIdx += 1
            continue

        newCoin = highestReached + 1
        highestReached += C * newCoin
        res += 1
        
    return res


T = int(raw_input())
for testId in range(T):
    C, D, V = inputInts()
    coins = inputInts()
    print "Case #{:d}: {:d}".format(testId+1, solve(C, V, D, coins))
