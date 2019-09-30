import sys
import itertools
import math
import collections
import functools

sys.setrecursionlimit(10000)


def inputInts():
    return map(int, raw_input().split())

def charsBeforeRepeat(s):
    L = len(s)
    # s = ABA, res => 2 because after 2 chars we can start a new pattern already
    for i in xrange(1, L+1):
        if s[i:] == s[0:L-i]:
            return i

def solve():
    K, L, S = inputInts()
    keyboard = raw_input()
    target = raw_input()

    if L > S:
        return 0

    # Compute keyboard frequency
    keyboardFreq = {}
    for k in keyboard:
        if k in keyboardFreq:
            keyboardFreq[k] += 1
        else:
            keyboardFreq[k] = 1

    # Make sure all necessary letter are there
    for k in target:
        if k not in keyboardFreq:
            return 0

    # First, what is the maximum number of repeats?
    spacing = charsBeforeRepeat(target)
    ideal = 0
    remaining = S
    while remaining >= L:
        ideal += 1
        remaining -= spacing

    # Second, what is the average number of repeats?

    keyboardProb = {}
    for k,v in keyboardFreq.iteritems():
        keyboardProb[k] = v / float(K)

    if L == 1:
        return ideal - S * keyboardProb[target[0]]

    res = 0.0
    runningProb = [0.0 for i in xrange(L-1)]
    for i in xrange(S):
        res += runningProb[L-2] * keyboardProb[target[L-1]]

        for j in xrange(L-2, 0, -1):
            runningProb[j] = runningProb[j-1] * keyboardProb[target[j]]
        runningProb[0] = keyboardProb[target[0]]

    return ideal - res
            


T = int(raw_input())
for testId in range(T):
    print "Case #{:d}: {:.10f}".format(testId+1, solve())
