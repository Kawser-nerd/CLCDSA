from sys import *
from numpy import *


def GetStringFromNumber(length, M):
    resstr = ''
    for i in range(length-1, -1, -1):
        res = M / 2 ** i
        resstr += str(res)
        M -= 2 ** i * res
    return resstr

def solve(T, B, M):
    if M > 2 ** (B - 2):
        print "Case #%d: IMPOSSIBLE" % (T + 1)
    elif M == 2 ** (B - 2):
        print "Case #%d: POSSIBLE" % (T + 1)
        # Number 1
        print '0' + '1' * (B - 1)
        # Others
        for i in range(2, B + 1):
            str = ""
            str += '0' * i + '1' * (B - i)
            print str
    else:
        print "Case #%d: POSSIBLE" % (T + 1)
        print '0' + GetStringFromNumber(B-2, M) + '0'
        for i in range(2, B + 1):
            str = ""
            str += '0' * i + '1' * (B - i)
            print str
        
        
cases = int(raw_input())
for T in xrange(cases):
    B, M = raw_input().split()
    B = int(B)
    M = int(M)
    solve(T, B, M)
