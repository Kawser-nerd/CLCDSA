import sys
sys.path.insert(0, '/home/rishig/codejam/')
from library import *

def d(o,e,N):
    t = (2*N-(e-o)+1)*(e-o)
    assert not t % 2
    return t / 2

def solvecase(case):
    N,M = readints(f)
    # o e p
    A = [readints(f) for i in range(M)]

    # calc actual cost
    actual = 0
    for o,e,p in A:
        actual += d(o,e,N)*p
        actual = actual % 1000002013

    # calc new cost
    elog = defaultdict(int)
    for o,e,p in A:
        elog[o] += p
        elog[e] -= p
    ee = sorted(elog.items())

    total = 0
    stack = []
    for stop,p in ee:
        if p == 0:
            continue
        if p > 0:
            stack.append((stop, p))
        if p < 0:
            count = 0
            while count < -p:
                ss,sp = stack.pop()
                count += sp
                total += d(ss, stop, N) * sp
                total = total % 1000002013
            assert count+p >= 0
            if count+p:
                stack.append((ss, count+p))
                total -= d(ss, stop, N) * (count+p)
                total = total % 1000002013

    return (actual-total) % 1000002013

if __name__ == '__main__':
    f = file(sys.argv[1])
    T = readint(f)
    sys.stderr.write(strftime("%H:%M:%S\n"))
    for case in range(1,T+1):
        ans = solvecase(case)
        print 'Case #%d: %s' % (case, ans)
        if T <= 15 or case == 1 or case % max((T//10),5) == 0:
            sys.stderr.write('completed case %d, ' % case)
            sys.stderr.write(strftime("%H:%M:%S\n"))

