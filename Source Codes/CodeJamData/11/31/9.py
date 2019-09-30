#!/usr/bin/python

import sys
from itertools import islice

def solve(pic):
    for r in xrange(len(pic) - 1):
        for c in xrange(len(pic[0]) - 1):
            if pic[r][c] == '#' and pic[r][c+1] == '#' and pic[r+1][c] == '#' and pic[r+1][c+1] == '#':
                pic[r  ][c  ] = '/'
                pic[r  ][c+1] = '\\'
                pic[r+1][c  ] = '\\'
                pic[r+1][c+1] = r'/'
    has_blue = sum(1 for row in pic for cell in row if cell == '#')
    if has_blue:
        return None
    else:
        return pic

def main():
    T = int(next(sys.stdin))
    for t in xrange(1, T+1):
        R, C = map(int, next(sys.stdin).split())
        pic = list(list(row.strip()) for row in islice(sys.stdin, R))
        newpic = solve(pic)
        print "Case #%s:" % (t,)
        if not newpic:
            print "Impossible"
        else:
            for row in newpic:
                print "".join(row)

main()
