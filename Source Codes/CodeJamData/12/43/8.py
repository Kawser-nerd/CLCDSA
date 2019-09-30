import math

import sys

sys.setrecursionlimit(3000)

testcases = int(raw_input())

n = None
h = None
output = None

def recurse (a, b, i, incl):
    if a == b:
        return True

    cont = 1
    j = a
    for k in range(a, b):
        if h[k] <= k or h[k] > b:
            return False
        if h[k] == b:
            output[k] = int(output[b] - math.ceil(incl * (b - k)) - cont)
            cont += 1
            if not recurse(j, k, i+1, float(output[b] - output[k]) / (b - k)):
                return False
            j = k+1
    return True

for tc in range(1, testcases+1):
    n = int(raw_input())
    h = map(lambda a: int(a) - 1, raw_input().split())

    output = [0] * n
    output[n-1] = 1000000000

    if recurse(0, n-1, 1, 0):
        mini = min(output)
        output = map(lambda a: a - mini, output)
        print "Case #%d: %s" % (tc, ' '.join(map(str, output)))
    else:
        print "Case #%d: Impossible" % tc
