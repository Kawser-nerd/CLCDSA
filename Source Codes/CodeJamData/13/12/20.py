#!python
# -*- coding: utf-8 -*-

import sys

T = int(sys.stdin.readline().strip())
for index in range(1, T + 1):
	(E, R, N) = [int(x) for x in sys.stdin.readline().split()]
	V = [int(x) for x in sys.stdin.readline().split()]
	
	ue = [E for x in V]
	le = [0 for x in V]
	ans = 0
	while True:
		maxval = max(V)
		if maxval == 0:
			break
		for i in range(N):
			if V[i] == maxval:
				ans += V[i] * (ue[i] - le[i])
				V[i] = 0
				for j in range(i + 1, N):
					if V[j] == 0:
						break
					if R * (j - i) >= E:
						break
					ue[j] = R * (j - i)
					le[j] = min(le[j], ue[j])
				for j in range(i - 1, -1, -1):
					if V[j] == 0:
						break
					if ue[i] - R * (i - j) <= 0:
						break
					le[j] = ue[i] - R * (i - j)
				break
	
	print "Case #%d: %d" % (index, ans)
	