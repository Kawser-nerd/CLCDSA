#!/usr/bin/env python

import sys
input = sys.stdin

def main():
    T = int(sys.stdin.readline())
    for test in range(1, T + 1):
        N, L, H = map(int, sys.stdin.readline().split())
        v = map(int, sys.stdin.readline().split())
        assert len(v) == N

        found = False
        for i in range(L, H + 1):
            ok = True
            for j in range(N):
                if not v[j] % i == 0 and not i % v[j] == 0:
                    ok = False
                    break

            if ok:
                found = True
                print "Case #%d: %d" % (test, i)
                break

        if not found:
            print "Case #%d: NO" % test
    return

if __name__ == '__main__':
    main()
