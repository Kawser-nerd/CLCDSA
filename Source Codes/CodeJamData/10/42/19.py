from sys import stdin
from itertools import *

memo = {}

def best(lo,rng,missed):
	global m,P,memo
	
	key = (lo,rng,missed)
	if memo.has_key(key):
		return memo[key]

	nrng = rng - 1
	if rng == 1:
		if min(m[2*lo], m[2*lo+1]) > missed:
			ret = 0
		else:
			ret = P[nrng][lo]
	else:
		ret = P[nrng][lo] + best(2*lo,nrng,missed) + best(2*lo+1,nrng,missed)
		clo = 2**rng * lo
		chi = clo + 2**rng
		if all(( m[x] > missed for x in xrange(clo,chi) )):
			ret = min(ret, best(2*lo,nrng,missed+1) + best(2*lo+1,nrng,missed+1))

	memo[key] = ret
	return ret

def answer(arg):
	global t,m,P,memo
	t,m,P = arg
	
	#print t
	#print m
	#for l in P:
		#print l

	memo.clear()
	return best(0,t,0)

def case(it):
	while 1:
		t = int(it.next())
		m = map(int, it.next().split())
		P = [ map(int, l.split()) for l in islice(it, t) ]
		yield (t,m,P)

stdin.next()
for cn,d in enumerate(case(stdin)):
	print "Case #%d: %d" % (cn+1, answer(d))
