import imp

#!/usr/bin/python

import sys

def iline(): return map( int, raw_input().strip().split() )

def test():
    B, N = iline()
    M = iline()
    
    def solve():
        L = 0
        R = max(M) * N
        while L < R:
            T = (L+R)/2
            n = sum( T//m+1 for m in M )
            if n >= N:
                R = T
            else:
                L = T+1
             
        n = sum( L//m+1 for m in M )
        k = [ i+1 for i, m in enumerate(M) if L%m == 0 ][N-n-1]
        print k
        
    return solve
        
        
if __name__ == '__main__':
    T = input()
    for i in xrange(1, T+1):
        print 'Case #%d:' % i,
        test()()

