from __future__ import print_function
import sys
from sys import stdin


def eprint(*args, **kwargs):
    print(*args, file=sys.stderr, **kwargs)


def ln(f=int):
	return list(map(f,stdin.readline().strip().split()))

T, = ln()
INF = float('inf')

for test in range(T):
	N,K = ln()

	xs = [(N,1)]

	h = {}
	h[N] = 1

	while True:
		n,q = max(h.items())
		a = n//2
		b = n-a-1
		del h[n]

		if not a in h:
			h[a] = 0
		if not b in h:
			h[b] = 0

		if a==b:
			h[a] += 2*q
		else:
			h[a] += q
			h[b] += q
		
		if K <= q:
			res_mx = max(a,b)
			res_mn = min(a,b)
			break
		K -= q

	print ("Case #" + str(test+1) + ": " + str(res_mx) + " " + str(res_mn))


