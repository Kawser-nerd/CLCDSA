import sys
import random
import re
from itertools import permutations

from collections import Counter


def solve():
    s = sys.stdin.readline().replace('\n','')
    
    c = Counter()
    
    for x in s:
        c[x] += 1
    
    sol = [None for i in xrange(10)]
    
    sol[0] = s.count('Z')
    sol[6] = s.count('X')
    sol[2] = s.count('W')
    sol[4] = s.count('U')
    sol[8] = s.count('G')
    sol[3] = s.count('H') - sol[8]
    sol[5] = s.count('F') - sol[4]
    sol[7] = s.count('V') - sol[5]
    sol[9] = s.count('I') - sol[6] - sol[8] - sol[5]
    sol[1] = s.count('N') - sol[7] - 2*sol[9]
    
    
    
    check = Counter()
    letters = ['ZERO', 'ONE', 'TWO', 'THREE', 'FOUR', 'FIVE', 'SIX', 'SEVEN', 'EIGHT', 'NINE']
    
    for i in xrange(10):
        for x in letters[i]:
            check[x] += sol[i]
    """
    print check
    print c
    """
    for x in check:
        if check[x] > 0:
            assert check[x] == c[x]
    
    solution = ""
    for i in xrange(10):
        solution += str(i) * sol[i]
    print solution


if __name__ == '__main__':
    t = int(sys.stdin.readline())
    for i in xrange(t):
        print "Case #%d:" % (i+1),
        solve()

