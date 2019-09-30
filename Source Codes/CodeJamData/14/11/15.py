#!/usr/bin/python

import sys

def countBit(x):
	return 0 if x==0 else (x&1)+countBit(x>>1)

def trans(s, m):
	return ''.join([ chr(ord(c)^((m>>i)&1)) for (i,c) in enumerate(s) ])

TT = int(sys.stdin.readline())

for T in xrange(1,TT+1):
	N, L = map(int, sys.stdin.readline().split())
	A = sys.stdin.readline().split()
	B = sys.stdin.readline().split()

	ans = L+1
	for m in xrange(1<<L):
		cnt = countBit(m)
		if cnt >= ans: continue
		A2 = [ trans(s,m) for s in A ]
		if set(A2) == set(B):
			ans = cnt

	anss = "NOT POSSIBLE" if ans == L+1 else str(ans)
	print "Case #%d: %s" % (T, anss)


