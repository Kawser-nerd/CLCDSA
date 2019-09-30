import sys
import random
import re
from itertools import permutations

import copy


def solve():
    a, b = sys.stdin.readline().split()
    
    l = len(a)
    assert len(a) == len(b)
    
    besta = None
    bestb = None
    
    weight = (10**(l+2), 0, 0)
    
    aa = [x for x in a]
    bb = [x for x in b]
    
    for i in xrange(l+1):
        # the first different digit is the i-th
        for j in xrange(i):
            # put the first i digit equal (if possible)
            if a[j] == b[j] != '?':
                pass
            elif a[j] == b[j] == '?':
                aa[j] = '0'
                bb[j] = '0'
            elif a[j] == '?':
                aa[j] = bb[j]
            elif b[j] == '?':
                bb[j] = aa[j]
            else:
                # impossible
                print besta, bestb
                return
        
        if i == l:
            # fantastic, they are equal!
            aaa = int(''.join(aa))
            bbb = int(''.join(bb))
            w = (abs(aaa-bbb), aaa, bbb)
            if w < weight:
                besta = copy.copy(''.join(aa))
                bestb = copy.copy(''.join(bb))
                weight = w
        
        # put the i-th digit different
        if i < l:
            for p in [str(x) for x in xrange(10)]:
                for q in [str(x) for x in xrange(10)]:
                    if p == q:
                        continue
                    
                    if not a[i] in ['?', p]:
                        continue
                    
                    if not b[i] in ['?', q]:
                        continue
                    
                    
                    aa[i] = p
                    bb[i] = q
                    
                    for j in xrange(i+1, l):
                        # complete the numbers
                        if a[j] == '?':
                            if p < q:
                                aa[j] = '9'
                            else:
                                aa[j] = '0'
                        
                        if b[j] == '?':
                            if p > q:
                                bb[j] = '9'
                            else:
                                bb[j] = '0'
                    
                    aaa = int(''.join(aa))
                    bbb = int(''.join(bb))
                    w = (abs(aaa-bbb), aaa, bbb)
                    if w < weight:
                        besta = copy.copy(''.join(aa))
                        bestb = copy.copy(''.join(bb))
                        weight = w
                    
    print besta, bestb


if __name__ == '__main__':
    t = int(sys.stdin.readline())
    for i in xrange(t):
        print "Case #%d:" % (i+1),
        solve()
    





