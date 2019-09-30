import imp, sys

sys.modules["utils"] = __mod = imp.new_module("utils")
exec """#!/usr/bin/python

from itertools import chain, repeat, izip

def line(*args):
	L = raw_input().strip().split()
	L = izip( L, chain( args, repeat(str) ) )
	return [ type(data) for data, type in L ]	
	
def iline(): return map( int, raw_input().strip().split() )
def fline(): return map( float, raw_input().strip().split() )""" in vars(__mod)

#!/usr/bin/python

from utils import iline
from math import atan2, pi
import sys

def test():
    N, = iline()
    P = [ iline() for i in xrange(N) ]
    
    def solve():
        print
        for px, py in P:
            Q = [ (atan2(qy-py, qx-px), (qx-px, qy-py)) for qx, qy in P if px != qx or py != qy ]
            N = len(Q)
            Q.sort()
            Q.extend([ (q + 2*pi,pos) for q,pos in Q ])
            a = 0    
            ans = N
            for b in xrange(N, len(Q)):
                a = max( a, b-N )
                while a < b and Q[b][1][0]*Q[a][1][1] - Q[b][1][1]*Q[a][1][0] >= 0:
                    a += 1
                ans = min( ans, b-a )
            
            print ans
        
    return solve
        
        
if __name__ == '__main__':
    T = input()
    for i in xrange(1, T+1):
        print 'Case #%d:' % i,
        test()()

