#!/usr/bin/env python2.5

M = 2 * 3 * 5 * 7

from collections import defaultdict

def solve_case(digits):
    # solution: dynamic programming from right to end
    # the state is {modulo M} X {number of consequtive digits to the right}
    digits, d = digits[:-1], digits[-1]
    state = defaultdict(int)
    state[d, 1] = 1
    for d in reversed(digits):
        res = defaultdict(int)
        for ((m, numlen), ways) in state.iteritems():
            # plus
            res[(d + m) % M, 1] += ways
            # minus
            res[(d - m) % M, 1] += ways
            # concatenate
            res[(d * 10**numlen + m) % M, numlen + 1] += ways
        state = res

##    import pprint
##    pprint.pprint(state)

    return sum(ways
               for ((m, numlen), ways) in state.iteritems()
               if ugly(m))

def ugly(n):
    return n % 2 == 0 or n % 3 == 0 or n % 5 == 0 or n % 7 == 0

def main(lines):
    lines = (line.strip() for line in lines)
    
    N = int(lines.next())
    for case in range(1, N + 1):
        digits = [int(d) for d in lines.next()]
        print "Case #%s: %s" % (case, solve_case(digits))
        
if __name__ == '__main__':
    import fileinput
    main(fileinput.input())
