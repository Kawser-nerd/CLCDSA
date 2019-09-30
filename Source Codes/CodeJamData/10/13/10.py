# -*- coding: utf-8 -*-

'''
http://code.google.com/codejam/contest/dashboard?c=544101#s=p2
'''

import sys,math

def lin(): return sys.stdin.readline()
def ints(): return [int(s) for s in lin().split()]

phi = (1 + math.sqrt(5))/2

def nums(a, B1, B2):
    if B1<=a<B2:
        return nums(a,B1,a) + nums(a,a+1,B2)
    assert a<=B1<=B2 or B1<=B2<=a
    if B1>=a:
        return max(0, B2 + 1 - max(B1, int(math.floor(a*phi)+1)))
    if B2<=a:
        return max(0, 1 + min(B2, int(math.floor(a/phi))) - B1)
    assert False

T = int(lin())
for casenum in range(T):
    (A1, A2, B1, B2) = ints()
    if A2-A1 > B2-B1:
        A1, A2, B1, B2 = B1, B2, A1, A2

    ans = 0
    for a in range(A1, A2+1):
        ans += nums(a, B1, B2)

    print "Case #%d: %s" % (casenum+1, ans)
