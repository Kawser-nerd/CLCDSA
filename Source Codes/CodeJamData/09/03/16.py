#!/usr/bin/python

from sys import stdin, stdout
from collections import defaultdict

stCount = 'welcome to code jam'
mapCount = defaultdict(lambda: [])
for i, c in enumerate(stCount):
    mapCount[c].append(i)

def rsreadline():
    return stdin.readline().rstrip('\r\n')

def main():
    cCase = int(rsreadline())
    for iCase in range(0, cCase):
        r = defaultdict(lambda: 0)
        r[0] = 1

        st = rsreadline()
        for c in st:
            for p in mapCount[c]:
                if r.has_key(p):
                    r[p+1] += r[p]

        print 'Case #%d: %04d' % (iCase+1, r[len(stCount)]%10000)
        stdout.flush()

main()
