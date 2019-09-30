#!/usr/bin/python

import sys

# -------------------------------------------------------------------------------------------------

def all_value(it, values):
    return all( ( x in values for x in it ) )

def any_value(it, values):
    return any( ( x in values for x in it ) )

# -------------------------------------------------------------------------------------------------

class Problem(object):

    def __init__(self, i, alines):
        assert(len(alines) == 4)

        self.arr = alines
        self.i = i

        self.a = self.access()
        print "%s" % alines
        assert(all_value( ( len(x) for x in alines ), [4] ) )

    def access(self):
        def ret(i, j):
            assert (i<4)
            assert (j<4)

            v = self.arr[i][j]
            assert(v in ['X', 'O', '.', 'T'])

            return v

        return ret

    def itdiag1(self):
        return ( self.a(i,i) for i in range(4) )

    def itdiag2(self):
        return ( self.a(i,3-i) for i in range(4) )

    def itrow(self, row):
        assert(row in xrange(4))
        return ( self.a(row, i) for i in range(4) )

    def itcol(self, col):
        assert(col in xrange(4))
        return ( self.a(i, col) for i in range(4) )

    def it(self):
        return ( self.a(i/4, i%4) for i in range(16) )

    def all_iters(self):
        return [ self.itdiag1(), self.itdiag2() ] + \
            [ self.itrow(row) for row in range(4) ] + \
            [ self.itcol(col) for col in range(4) ]

# -------------------------------------------------------------------------------------------------

class Solver(object):

    def __init__(self, prob):
        self.prob = prob

    def check_win(self, v):
        if any ( ( all_value(it, [v, 'T']) for it in self.prob.all_iters()) ): return True
        return False

    def solve(self):
        if self.check_win('X'):
            self.res = "X won"
            return

        if self.check_win('O'):
            self.res = "O won"
            return

        if any_value(self.prob.it(), ['.']):
            self.res = "Game has not completed"
            return

        self.res = "Draw"

    def result(self):
        return "Case #%d: %s" % (self.prob.i, self.res)


# -------------------------------------------------------------------------------------------------

def read_int(f):
    return int(f.readline())

def read_problem(f, pcnt):
    lines = [ f.readline().strip() for i in range(4) ]
    return Problem(pcnt, lines)


fin = open(sys.argv[1], "r")
fout = open("out.txt", "w")

N = read_int(fin)
for i in range(N):
    p = read_problem(fin, i+1)
    fin.readline()
    s = Solver(p)
    s.solve()
    fout.write("%s\n" % s.result())



