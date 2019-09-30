#!/usr/bin/env python
# -*- mode:python; coding:utf-8; indent-tabs-mode:nil -*-
#
# Problem C. Equal Sums
# http://code.google.com/codejam/contest/1836486/dashboard#s=p2
#

import sys
import itertools


def solve(S):
    sums = dict((s, (s, )) for s in S)
    for n in range(2, len(S)):
        for pair in itertools.combinations(S, n):
            num = sum(pair)
            if num in sums:
                return '\n%s\n%s' % (' '.join(map(str, sums[num])), ' '.join(map(str, pair)))
            sums[num] = pair
    return ' Impossible'


def main(INPUT, OUTPUT):
    T = int(INPUT.readline())
    for index in range(T):
        # 進捗表示
        sys.stderr.write('#%d\r' % (index + 1))
        data = map(int, INPUT.readline().strip().split())
        OUTPUT.write('Case #%d:%s\n' % (index + 1, solve(data[1:])))


def makesample(N, Smax, T=10):
    import random
    print T
    for index in range(T):
        print N, ' '.join(str(random.randint(1, Smax)) for n in range(N))


if __name__ == '__main__':
    if len(sys.argv) > 1:
        if ('-makesample', 'small') == tuple(sys.argv[1:]):
            makesample(20, 10**5)
        elif ('-makesample', 'large') == tuple(sys.argv[1:]):
            makesample(500, 10**12)
        else:
            print 'usage: %s [-makesample <small|large>]' % sys.argv[0]
    else:
        main(sys.stdin, sys.stdout)

