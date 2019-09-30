# coding='utf-8'

import os, sys, time, random
time.clock()

sys.stdin = open('A-large.in')
sys.stdout = open('A-large.out', 'w')

def flip(x):
	return int(str(x)[::-1].lstrip('0'))

def Preprocess():
	global f
	n = 100002
	f = [n] * n
	f[1] = 1
	for i in range(1, n-1):
		f[i+1] = min(f[i+1], f[i] + 1)
		if flip(i) < n:
			f[flip(i)] = min(f[flip(i)], f[i]+1)

def GetCheckPoint(x):
	l = len(str(x))
	if str(x).endswith('0' * (l-l//2)):
		return GetCheckPoint(x-1)
	else:
		ret = int(str(x)[:l//2] + '0'* (l-l//2-1) + '1')
		if str(x)[:l//2] == '1' + '0'*(l//2-1):
			return GetCheckPoint(ret - 2)
		return ret

def Calc(n):
	if n < 100: return f[n]
	cp = GetCheckPoint(n)
	return Calc(flip(cp)) + 1 + n - cp


def Work():
	n = int(input().strip())
	return Calc(n)

if __name__ == '__main__':
	Preprocess()
	T = int(input())
	for i in range(T): 
		print('Case #%d: %d' % (i+1, Work()))
	'''
	for i in range(1, 1000000):
		if i % 1000 == 0: print(i)
		if f[i] != Calc(i): print('sb ! ', i)
		#if f[i] < f[i-1]: print(i, f[i], '')
		#print(f[i], end=' ')
	'''
	sys.stderr.write('completed %.3f\n' % time.clock())
	
	
