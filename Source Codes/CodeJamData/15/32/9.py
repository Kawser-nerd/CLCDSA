#!/usr/bin/env python

import sys

def readline():
    return map(int, raw_input().strip().split())

def solve():
    k, l, s = readline()
    keys = raw_input().strip()
    word = raw_input().strip()
    if set(word) - set(keys):
        return 0.0
    t = [max(j for j in xrange(i) if word.startswith(word[i-j:i])) for i in xrange(1, l+1)]
    bring = 1 + (s - l) // (l - t[-1])
    d = [[0] * l for i in xrange(s+1)]
    kp = {kk: 0 for kk in set(keys)}
    for kk in keys:
        kp[kk] += 1
    for si in xrange(s-1, -1, -1):
        for p in xrange(l):
            r = 0.0
            for kk, kc in kp.iteritems():
                pp = p
                while pp > 0 and kk != word[pp]:
                    pp = t[pp-1]
                if kk == word[pp]:
                    pp += 1
                if pp == l:
                    r += kc
                    pp = t[pp-1]
                r += d[si + 1][pp] * kc
            r /= k
            d[si][p] = r
    return bring - d[0][0]


def main():
    t = int(raw_input().strip())
    for i in xrange(1, t + 1):
        ret = solve()
        print 'Case #{}:'.format(i), ret
        print >> sys.stderr, 'Case #{}:'.format(i), ret

if __name__ == '__main__':
    main()
