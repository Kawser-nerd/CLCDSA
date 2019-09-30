"""Usage:
    X.py < X.in > X.out
"""


class Solver(object):

    @classmethod
    def setup(cls, infile):
        cls.data = {}

    def __init__(self, infile, tc):
        self.tc = tc
        self.I = I = map(int, infile.next().split())

    def solve(self):
        import itertools as it
        S = self.I[1:]
        seen = {}
        for n in xrange(1,4):
            for s in it.combinations(S, n):
                ss = sum(s)
                if ss in seen:
                    return 'Case #%s:\n%s\n%s\n' % (self.tc, ' '.join('%d' %i for i in s), ' '.join('%d' %i for i in seen[ss]),)
                seen[ss] = s
        return 'Case #%s: Impossible\n' % (self.tc,)


if __name__ == '__main__':
    import sys
    T = int(sys.stdin.next())
    Solver.setup(sys.stdin)
    for t in xrange(1, T+1):
        sys.stdout.write(Solver(sys.stdin, t).solve())
