def mtree(v,i,j):
	if j - i == 1:
		x = lambda:1
		x.m = v[i]
		x.l = x.r = None
		return x
	k = i + j >> 1
	x = lambda:1
	x.l = mtree(v,i,k)
	x.r = mtree(v,k,j)
	x.m = max(x.l.m, x.r.m)
	return x

def rem(v,t):
	if v.m < t:
		return
	if v.l:
		if v.l.m >= t:
			rem(v.l,t)
			v.m = max(v.l.m,v.r.m)
		else:
			rem(v.r,t)
			v.m = max(v.l.m,v.r.m)
	else:
		v.m = -10**100

def getmax(v,t):
	if v.m <= t:
		return v.m
	if v.l:
		if v.l.m > t:
			return getmax(v.l,t)
		else:
			ww = getmax(v.r,t)
			if ww is None or ww < 0:
				ww = v.l.m
			return ww

from collections import *


z = input()
for cas in xrange(1,z+1):
	n, x = map(int, raw_input().strip().split())
	v = map(int, raw_input().strip().split())
	v.sort()
	tree = mtree(v,0,len(v))
	count = defaultdict(int)
	for vv in v:
		count[vv] += 1
	ans = 0
	for i in xrange(len(v)-1,-1,-1):
		if not count[v[i]]: continue
		count[v[i]] -= 1
		rem(tree,v[i])
		ans += 1
		w = getmax(tree,x-v[i])
		if w is not None and w >= 0:
			count[w] -= 1
			rem(tree,w)

	print "Case #%s: %s" % (cas, ans)
