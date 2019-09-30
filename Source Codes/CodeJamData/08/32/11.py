import math
import re

fp = open('B-small-attempt0.in')

cases = int(fp.readline())
case = 0

odp = [2, 3, 5, 7]

def countUgly(num, sum):
    if len(num) == 0:
        if isUgly(sum):
            return 1
        else:
            return 0
    cug = 0
    for i in range(1, len(num) + 1):
        start = num[i:]
        doOp = int(num[:i])
        sumPlus = sum + doOp
        cug += countUgly(start, sumPlus)
        sumMinus = sum - doOp
        cug += countUgly(start, sumMinus)
    return cug

def isUgly(c):
    if c == 0:
        return True
    for o in odp:
        if c % o == 0:
            return True
    return False

for case in range(0, cases):
    num = fp.readline()
    num = num[:-1]
    cug = countUgly(num, 0)
    cug /= 2
    print "Case #%i: %i" % (case + 1, cug)

fp.close()
