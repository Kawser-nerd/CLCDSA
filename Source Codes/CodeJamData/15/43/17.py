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

# Small test cases only

from utils import iline, line

def test():
    N, = iline()
    sentences = [ set(line()) for i in xrange(N) ]
    
    yield
    
    answer = 1e100
    for bits in xrange(1<<(N-2)):
        words = [ set(), set() ]
        bits = 4*bits + 2
        for i, s in enumerate(sentences):
            language = 1 if (bits&(1<<i)) else 0
            words[language] |= s
            
        answer = min( answer, len(words[0] & words[1]) )
        
    print answer
        
        
        
if __name__ == '__main__':
    T = input()
    for i in xrange(1, T+1):
        print 'Case #%d:' % i,
        solver = test()
        if hasattr(solver, 'next'):
            list(solver)
        elif callable(solver):
            solver()

