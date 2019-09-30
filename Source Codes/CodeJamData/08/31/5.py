#!/usr/bin/env python2.5

def solve_case(P, K, L, freqs):
    # solution: sort freqs, fill keys in breadth-first order
    freqs = sorted(freqs, reverse=True)
    def gen_prices():
        for presses in range(1, P+1):
            for key in range(K):
                yield presses
    return sum(f * p for f, p in zip(freqs, gen_prices()))

def main(lines):
    lines = (line.strip() for line in lines)
    
    N = int(lines.next())
    for case in range(1, N + 1):
        P, K, L = [int(s) for s in lines.next().split()]
        freqs = [int(s) for s in lines.next().split()]
        assert len(freqs) == L
        print "Case #%s: %s" % (case, solve_case(P, K, L, freqs))
        
if __name__ == '__main__':
    import fileinput
    main(fileinput.input())
