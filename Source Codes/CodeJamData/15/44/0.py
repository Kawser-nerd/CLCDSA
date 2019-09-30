from sys import stdin

def getInt():
    return int(stdin.readline())

def getInts():
    return tuple(int(z) for z in stdin.readline().split())

# 3's come in sets of 2 rows

# Everything else is 2's and 1's 

# In a 1xC, it must be all 2's

# In a 2xC, if C is a multiple of 3 it can be **.
#                                             **.
# otherwise, must go around .****.
#                           **..** (so C must be a multiple of 6)

# In a 3xC, .***
#           .*.*
#           **.* (C must be a multiple of 4)

from fractions import gcd

def addin(dict, key, value):
    if key in dict:
        dict[key] += value
    else:
        dict[key] = value

def f(k,C,l):
    return k if l else 1

def lcm(a,b):
    return (a*b)/gcd(a,b)

numCases = getInt()
for case in xrange(1, 1+numCases):
    (R, C) = getInts()
    states = [{(0,1,False):1,(1,1,False):1}]+[{} for i in xrange(R)]
    for i in xrange(R):
        # print i, states[i]
        for (j,k,l) in states[i]:
            if j == 1 and (i + 2) <= R:
                addin(states[i+2], (0, k, l), states[i][(j,k,l)])
            if j == 0 and (i + 1) <= R:
                addin(states[i+1], (1, k, l), states[i][(j,k,l)])
            if j == 0 and (i + 2) <= R:
                if (C % 3) == 0:
                    addin(states[i + 2], (1, lcm(k, 3), True), 3 * states[i][(j,k,l)])
                if (C % 6) == 0:
                    addin(states[i + 2], (1, lcm(k, 6), True), 6 * states[i][(j,k,l)])
            if j == 0 and (i + 3) <= R:
                if (C % 4) == 0:
                    addin(states[i + 3], (1, lcm(k, 4), True), 4 * states[i][(j,k,l)])
    # print states[-1]
    ans = sum(states[-1][(j,k,l)]/f(k,C,l) for (j,k,l) in states[-1])
    print "Case #%d: %s" % (case, ans)

