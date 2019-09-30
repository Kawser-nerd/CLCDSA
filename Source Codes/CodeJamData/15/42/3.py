import sys


def climit(V, cr, t):
    cv = 0.0
    v = 0.0
    for ci, ri in cr:
        if v + ri * t >= V:
            cv += ci * (V - v)
            v = V
            if abs(ci - cr[0][0]) < 1.0e-9:
                return cr[0][0]
            return cv / v
        else:
            cv += ci * ri * t
            v += ri * t
    return None
            

def compute(N, V, C, RC):
    crinc = sorted([(c, r) for r, c in RC])
    crdec = sorted([(c, r) for r, c in RC], reverse=True)
    if crinc[0][0] > C or crinc[-1][0] < C:
        return "IMPOSSIBLE"
    a = 0.0
    b = 10e+10
    while b - a > 1.0e-9:
        t = (a + b) / 2.0
        if t <= a or t >= b:
            break
        cmin = climit(V, crinc, t)
        if cmin is None:
            a = t
            continue
        cmax = climit(V, crdec, t)
        if cmax is None:
            # shouldn't happen
            a = t
            continue
        if C < cmin or C > cmax:
            a = t
        else:
            b = t
    return (a + b) / 2.0



def parse():
    N, V, C = sys.stdin.readline().strip().split()
    N = int(N)
    V = float(V)
    C = float(C)
    RC = []
    for i in xrange(N):
        RC.append(map(float, sys.stdin.readline().strip().split()))
    return N, V, C, RC


if __name__ == "__main__":
    sys.setrecursionlimit(100000)
    T = int(sys.stdin.readline().strip())
    for i in xrange(T):
        data = parse()
        result = compute(*data)
        print "Case #%d: %s" % (i + 1, result)
