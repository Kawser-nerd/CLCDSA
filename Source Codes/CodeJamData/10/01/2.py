#!/usr/bin/python

import sys, re, string, math

def do_one_case(cnum):
    (n,k) = map(int,sys.stdin.readline().split())
    m = (1<<n) - 1
    print "Case #%d: %s" % (cnum, "ON" if (k&m)==m else "OFF")


def main():
    N = int(sys.stdin.readline().strip())
    for i in range(N):
        do_one_case(i+1)


if __name__ == "__main__":
    main()
