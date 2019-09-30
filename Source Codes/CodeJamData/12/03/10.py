#!/usr/bin/python3

import sys

def recycle(N,A,B):
	n = str(N)
	r = 0
	S = []
	for k in range(1,len(n)):
		if n[k] >= n[0]:
			p = int(n[k:] + n[:k])
			if (p > N) and (p <= B) and p not in S:
				S.append(p)
#				print(N,p)
				r += 1
	return r

def work(s):
	A,B = tuple(map(int,s.split()))
	n = sum(recycle(k,A,B) for k in range(A,B))
	return n

if __name__ == '__main__':
	T = int(sys.stdin.readline().strip())
	for i in range(T):
#		print(i,file=sys.stderr)
		s = work(sys.stdin.readline().rstrip())
		print('Case #{}: {}'.format(i+1, s))
