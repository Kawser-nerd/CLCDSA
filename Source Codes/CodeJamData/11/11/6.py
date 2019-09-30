import sys
from fractions import gcd

def main(argv=None):
    if not argv:
        argv = sys.argv[1:]
    filename = argv[0] if argv else 'test.in'

    with open(filename) as f:
        numCases = int(f.readline())
        for caseNo in xrange(1, numCases+1):
            toks = f.readline().split()
            N, PD, PG = [int(tok) for tok in toks]
                
            poss = solve(N, PD, PG)
            st = "Possible" if poss else "Broken"
            print 'Case #{0}: {1}'.format(caseNo, st)

def solve(N, PD, PG):
    if PG == 100 and PD < 100:
        return False

    if PG == 0 and PD > 0:
        return False

    pdf = 100 / gcd(PD, 100)
    pgf = 100 / gcd(PG, 100)

    # print pdf, pgf

    return pdf <= N

if __name__ == '__main__':
    main()
