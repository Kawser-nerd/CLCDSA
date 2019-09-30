#!/usr/bin/env pypy3
def m(p):
	return lambda x: x*p

def aa(u, v):
	for x, y in zip(u, v):
		yield x+y
		
def get_p(a):
	u = [1]
	for x in a:
		u = list(aa([0,0] + list(map(m(x), u)), list(map(m(1-x), u))+[0,0]))
	return u[len(u) >> 1]
for i in range(int(input())):
	n, k = map(int, input().split())
	p = sorted(list(map(float, input().split())))
	r = 0
	for j in range(k+1):
		v = p[:j] + p[::-1][:k-j]
		assert(len(v) == k)
		r = max(r, get_p(v))
	print("Case #%d: %.12f"%(i+1, r))
