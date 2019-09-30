# coding=utf-8

import os, sys, time, random
time.clock()

sys.stdin = open('B-small-attempt1.in')
sys.stdout = open('B-small-attempt1.out', 'w')

def Work():
	inp = input().split()
	n, X, C = int(inp[0]), float(inp[1]), float(inp[2])
	ss = []
	for i in range(n):
		ss.append(list(map(float, input().split())))
	if len(ss) == 2:
		a, b = ss[0][1], ss[1][1]
		if a == b:
			ss = [ [ss[0][0]+ss[1][0], ss[0][1]] ]
		else:
			alpha = (C - b) / (a - b)
			if not 0 <= alpha <= 1: return 'IMPOSSIBLE'
			return '%.12f' % max([X * alpha / ss[0][0], X*(1-alpha) / ss[1][0]])
	if len(ss) == 1:
		if ss[0][1] != C: return 'IMPOSSIBLE'
		return '%.12f' % (X / ss[0][0])
	return ''

if __name__ == '__main__':
	T = int(input())
	for i in range(T): 
		print('Case #%d: %s' % (i+1, Work()))
	sys.stderr.write('completed %.3f\n' % time.clock())
	
	
