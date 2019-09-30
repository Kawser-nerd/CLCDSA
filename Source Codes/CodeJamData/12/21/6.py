#!/usr/bin/env python
# -*- mode:python; coding:utf-8; indent-tabs-mode:nil -*-
#
# Problem A. Safety in Numbers
# http://code.google.com/codejam/contest/1836486/dashboard#s=p0
#

import sys


def solve(slist):
    #print 's', slist

    # the sum of the judge-assigned point values of all contestants.
    X = sum(slist)

    # 均等に分けるとこれだけ必要
    need = 1.0 * (sum(slist) + X) / len(slist)

    # 必要点に達していないもので分け合う
    sublist = filter(lambda s: s < need, slist)
    need = 1.0 * (sum(sublist) + X) / len(sublist)
    #print 'need', need

    # あとどれだけ必要?
    left = [max(need - s, 0) for s in slist]
    #print 'left', left

    # 百分率にする
    result = [100 * y / sum(left) for y in left]
    return ' '.join(map(str, result))


def main(INPUT, OUTPUT):
    T = int(INPUT.readline())
    for index in range(T):
        # 進捗表示
        sys.stderr.write('#%d\r' % (index + 1))
        data = map(int, INPUT.readline().strip().split())
        OUTPUT.write('Case #%d: %s\n' % (index + 1, solve(data[1:])))


def makesample(Nmax, T):
    import random
    print T
    for index in range(T):
        N = random.randint(2, Nmax)
        print N, ' '.join(str(random.randint(0, 100)) for n in range(N))


if __name__ == '__main__':
    if len(sys.argv) > 1:
        if ('-makesample', 'small') == tuple(sys.argv[1:]):
            makesample(10, 20)
        elif ('-makesample', 'large') == tuple(sys.argv[1:]):
            makesample(200, 50)
        else:
            print 'usage: %s [-makesample <small|large>]' % sys.argv[0]
    else:
        main(sys.stdin, sys.stdout)

