import itertools

def solve(wires):
    return sum(meet(a, b) for a, b in itertools.combinations(wires, 2))

def meet(a, b):
    a1, a2 = a
    b1, b2 = b
    return (a1 > b1) ^ (a2 > b2)


if __name__ == '__main__':
    import sys
    rl = iter(sys.stdin).next
    for case in range(1, int(rl())+1):
        N = int(rl())
        wires = [map(int, rl().split()) for _ in xrange(N)]
        print 'Case #%d: %s' % (case, solve(wires))
