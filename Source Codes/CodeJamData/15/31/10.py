#!/usr/bin/env python

def readline():
    return map(int, raw_input().strip().split())

def solve():
    r, c, w = readline()
    moves = (r - 1) * (c // w)
    if c >= 2 * w:
        z = (c // w) - 1
        moves += z
        c -= z * w
    if c == w:
        moves += w
    else:
        moves += w + 1
    return moves


def main():
    t = int(raw_input().strip())
    for i in xrange(1, t + 1):
        ret = solve()
        print 'Case #{}:'.format(i), ret

if __name__ == '__main__':
    main()
