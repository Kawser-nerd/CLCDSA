#!/usr/bin/python
# -*- coding: utf-8 -*-

from __future__ import division

import sys
import math

lines = sys.stdin.readlines()

T = int(lines[0])

def get_board(lines):
	y = []
	for l in lines:
		x = []
		for n in l:
			v = bin(int(n, 16))[2:]
			while len(v) < 4:
				v = "0" + v
			x.extend([int(i) for i in v])
		y.append(x)
	return y

answers = None

def solve(b, M, N):
	streaks = []
	nothingness = True
	for m in b:
		s = []
		last = []
		for n in m:
			if (len(last) == 0) or (last[-1] == n) or (n == None):
				#print("dumping", last)
				while len(last):
					s.append(len(last))
					last.pop()
			if n != None:
				nothingness = False
				last.append(n)
			else:
				s.append(0)
		#print("dumping", last)
		while len(last):
			s.append(len(last))
			last.pop()
		#print s, len(s)
		streaks.append(s)
	if nothingness: return
	largest = 0
	cuts = []
	for m in range(M):
		for n in range(N):
			want = b[m][n]
			if want == None: continue
			maxs = streaks[m][n]
			for s in range(min(M-m, maxs+1)):
				if b[m+s][n] != want:
					#print("bw", b[s+m][n], want)
					break
				want = 1 - want
				maxs = min(maxs, streaks[m+s][n])
				if maxs >= s + 1 and s + 1 >= largest:
					if s + 1 > largest:
						#print s + 1, n, m
						largest = s + 1
						cuts = [(n, m)]
					else:
						cuts.append((n, m))
	#print largest, cuts
	print >> sys.stderr, "cutting", largest, len(cuts)
	sys.stderr.flush()
	good_cuts = 0
	for (x, y) in cuts:
		if b[y][x] != None and b[y+largest-1][x] != None and b[y][x+largest-1] != None and b[y+largest-1][x+largest-1] != None:
			good_cuts += 1
			#print "cutting", x, y
			for j in range(largest):
				for i in range(largest):
					b[y+j][x+i] = None
	answers.append((largest, good_cuts))
	solve(b, M, N)

idx = 1
for t in range(1, T + 1):
	print >> sys.stderr, "working on", t
	sys.stderr.flush()
	l = [int(x) for x in lines[idx].split()]
	M = l[0]
	N = l[1]
	#print(M, N)
	b = get_board([x.strip() for x in lines[idx + 1 : idx + 1 + M]])
	idx += 1 + M
	answers = []
	solve(b, M, N)
	print "Case #%d: %d" % (t, len(answers))
	for (a, b) in answers:
		print a, b

