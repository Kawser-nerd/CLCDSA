import sys

_in = open(sys.argv[1])
def raw(): return _in.readline().rstrip('\n')
def ints(): return map(int, raw().split())
raw_input = raw # we all forget sometimes

class memoize:
    def __init__(self, function):
        self.fn = function
        self.memory = {}
    def __call__(self, *args):
        if args not in self.memory:
            self.memory[args] = self.fn(*args)
        return self.memory[args]

def minner(sol):
    return (-sol[0], -int(sol[1]), -int(sol[2]))

def maxxer(sol):
    return (sol[0], -int(sol[1]), -int(sol[2]))

def zeroer(sol):
    return (-abs(sol[0]), -int(sol[1]), -int(sol[2]))

comps = [minner, maxxer, zeroer]

@memoize
def rec(u, v, i, comparer):
    # returns (delta, u[-i:], v[-i:])
    if i == 0:
        return (0, "", "")
    sa, sb = u[-i], v[-i]

    poss_a = [int(sa)] if sa != '?' else range(10)
    poss_b = [int(sb)] if sb != '?' else range(10)
    best = None
    for a in poss_a:
        for b in poss_b:
            for comp in comps:
                delta, su, sv = rec(u, v, i-1, comp)
                sol = (((a - b) * (10**(i-1)) + delta), str(a)+su, str(b)+sv)
                if best is None or comparer(sol) > comparer(best):
                    best = sol
    return best

def solve(u, v):
    res = rec(u, v, len(u), zeroer) # probably wrong
    return '{} {}'.format(res[1], res[2])

if __name__ == '__main__':
    num_cases, = ints()
    for case_num in xrange(1, num_cases + 1):
        u, v = raw().split()
        print "Case #{}: {}".format(case_num, solve(u, v))
