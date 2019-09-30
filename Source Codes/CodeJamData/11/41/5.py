#! /usr/bin/python2

import random,re

eps = 1e-8

def time(s, v):
	return 1.*s/v

def solve():
	X,S,R,t,n = map(int, raw_input().split())
	X = float(X); S=float(S); R=float(R); t=float(t)
	l = []
	for i in range(n):
		b,e,w =  map(float, raw_input().split())
		d = e-b
		l.append((w,d))
		X-=d
	l.append((0,X))
	l.sort()
	#print l
	res = 0.
	#print t
	for s,d in l:
		#print s,d,')',
		runt = time(d, s+R)
		if runt > t+eps:
			res+=t
			d-=t*(s+R)
			t=0
		else:
			res+=runt
			d=0
			t-=runt
		res += time(d, S+s)
		#print res,t
	print "%.9lf" % res

def main():
	T = input()
	for i in range(1,T+1):
		print 'Case #%d:' % (i,),
		solve()

if __name__ == '__main__':
	main()
