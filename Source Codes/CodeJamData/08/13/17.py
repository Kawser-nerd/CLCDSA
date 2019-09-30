"""
SeeNoEvil's Solution to the "Numbers" problem, GCJ 2008, Round 1

Note: non-standard package psyco can be obtained from:
http://psyco.sourceforge.net/
"""

import sys, math
from decimal import Decimal, getcontext

def main():
    fin = file(sys.argv[1])
    fout = file(sys.argv[2], "wt")

    getcontext().prec = 50
    K = Decimal(3) + Decimal(5).sqrt()
     
    numCases = int(fin.readline())
    for case in xrange(numCases):
        exp = int(fin.readline())
        answer = Decimal(1)
        for n in xrange(exp):
            answer *= K
        fout.write("Case #%d: %s\n" % (case+1, ("000" + str(int(answer)))[-3:]))
   
if __name__ == "__main__":

    #try:
    #    import psyco
    #    psyco.bind(Add)
    #except ImportError:
    #    print 'Psyco not installed, the program will just run slower'

#    import cProfile
#    import pstats
#    cProfile.run("main()", "gcj.prof")
#    pstats.Stats("gcj.prof").strip_dirs().sort_stats(-1).print_stats()

    import doctest
    doctest.testmod()
   
    main()   
  