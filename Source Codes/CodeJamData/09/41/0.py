#!/usr/bin/env python
import os, sys, re, math
stdin = sys.stdin


T = int(stdin.readline())
for cs in range(1, T+1):
	N = int(stdin.readline())
	
	rows = []
	for each in range(N):
		s = stdin.readline().strip()
		assert len(s) == N
		num = 0
		for i in range(len(s)):
			if s[i] == '1':
				num = i
		rows.append(num)
		
	ans = 0
	
	for i in range(N):
		j = i
		while j < N and rows[j] > i:
			j += 1
		assert j < N
		
		for k in reversed(range(i, j)):
			rows[k+1], rows[k] = rows[k], rows[k+1]
			#print rows, i
			ans += 1
		
	print 'Case #%d: %d' % (cs, ans)
