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
        JJ = J = self.I[1:]
        X = float(sum(J))
        win = []
        lw = -1
        while len(win) > lw:
            lw = len(win)
            win.extend([j for j in J if j > ((X + sum(J)) / len(J))])
            J = [j for j in J if j <= ((X + sum(J)) / len(J))]
        res = dict((w,0.) for w in win)
        for j in J:
            res[j] = ((X + sum(J)) / len(J) - j) / X * 100.
        return 'Case #%s: %s\n' % (self.tc, ' '.join('%f' % res[j] for j in JJ))


if __name__ == '__main__':
    import sys
    T = int(sys.stdin.next())
    Solver.setup(sys.stdin)
    for t in xrange(1, T+1):
        sys.stdout.write(Solver(sys.stdin, t).solve())
