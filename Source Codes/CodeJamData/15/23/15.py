# coding='utf-8'

import os, sys, time, random
time.clock()
# only small

sys.stdin = open('C-small-1-attempt0.in')
sys.stdout = open('C-small-1-attempt0.out', 'w')


def Work():
	n = int(input().strip())
	sb = []
	for i in range(n):
		d, h, m = map(int, input().strip().split())
		for j in range(h):
			sb.append( (d, 360 / (m+j) ) )
	sb.sort(key=lambda d:d[-1], reverse=True)
	# 0 is faster
	if sb[0][1] == sb[1][1]: return 0

	ar1 = (360 - sb[1][0]) / sb[1][1]
	meet = (360 + sb[1][0] - sb[0][0]) / (sb[0][1] - sb[1][1])
	if meet <= ar1 + 1e-8: return 1
	return 0


if __name__ == '__main__':
	T = int(input())
	for i in range(T): 
		print('Case #%d: %d' % (i+1, Work()))
	sys.stderr.write('completed %.3f\n' % time.clock())
	
	
