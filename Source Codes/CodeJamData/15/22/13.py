# coding='utf-8'

import os, sys, time, random
time.clock()

sys.stdin = open('B-large.in')
#sys.stdin = open('input.txt')
sys.stdout = open('B-large.out', 'w')


def WorkInv(r, c, n):
	n = r * c - n
	B = 0
	vlist = []
	for i in range(r):
		for j in range(c):
			if (i + j) % 2 == 1: 
				ss = 4
				if i == 0: ss -= 1
				if i == r-1: ss -= 1
				if j == 0: ss -= 1
				if j == c-1: ss -= 1
				vlist.append(ss)
	rr = sum(vlist)
	if n <= 0: return rr
	vlist.sort(reverse=True)
	return rr - sum(vlist[:n])

def Work():
	r, c, n = map(int, input().strip().split())
	inv = WorkInv(r, c, n)
	B = 0
	vlist = []
	for i in range(r):
		for j in range(c):
			if (i + j) % 2 == 1: 
				B += 1
				continue
			ss = 4
			if i == 0: ss -= 1
			if i == r-1: ss -= 1
			if j == 0: ss -= 1
			if j == c-1: ss -= 1
			vlist.append(ss)
	n -= B
	if n <= 0: return 0
	vlist.sort()
	return min([sum(vlist[:n]), inv])


def Work1():
	r, c, n = map(int, input().strip().split())
	ret = 1000000
	for st in range(2**(r*c)):
		zz = [1 if st&(1<<i)>0 else 0 for i in range(r*c)]
		if sum(zz) != n: continue
		rr = 0
		for k, v in enumerate(zz):
			i, j = k // c, k % c
			if v == 0: continue
			if i > 0: rr += zz[(i-1)*c+j]
			if j > 0: rr += zz[i*c+j-1]
		ret = min([ret, rr])
	return ret


if __name__ == '__main__':
	T = int(input())
	for i in range(T): 
		print('Case #%d: %d' % (i+1, Work()))
	sys.stderr.write('completed %.3f\n' % time.clock())
	
	
