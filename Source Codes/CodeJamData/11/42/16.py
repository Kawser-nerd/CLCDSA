#!/usr/bin/env python

_FMT_ = 'Case #%d: %s\n'
f = open('in','r')
_T_ = int(f.readline())

import sys
if len(sys.argv) > 1:
	_jobs_ = _T_/4
	_jid_ = int(sys.argv[1])
	_t0_ = _jobs_ * _jid_
	_t1_ = _jobs_ *(_jid_+1)
	if _jid_ == 3: _t1_ = _T_
	g = open('out'+str(_jid_),'w')
else:
	_jid_ = -1
	_t0_ = 0
	_t1_ = _T_
	g = open('out','w')

def test(W, r1, r2, c1, c2):
	rc = 0.5*(r1+r2-1)
	cc = 0.5*(c1+c2-1)
	totr = 0
	totc = 0
	for r in xrange(r1,r2):
		for c in xrange(c1, c2):
			totr+=W[r][c]*(r-rc)
			totc+=W[r][c]*(c-cc)
	totr-=((W[r1][c1]+W[r1][c2-1]-W[r2-1][c1]-W[r2-1][c2-1])*(r1-rc))
	totc-=((W[r1][c1]-W[r1][c2-1]+W[r2-1][c1]-W[r2-1][c2-1])*(c1-cc))
	return (abs(totr)<0.001 and abs(totc)<0.001)
	
for _t_ in xrange(_T_): 

	#INPUT
	R,C,D  = (int(x) for x in f.readline().strip().split())

	W = []
	for r in xrange(R):
		line  = f.readline().strip()
		w = [int(x) for x in line]
		W.append(w)
	
	if _t_<_t0_ or _t_>=_t1_: continue

	L = min(R,C)
	done = False
	for l in xrange(L, 2, -1):
		for r1 in xrange(R+1-l):
			for c1 in xrange(C+1-l):
				if test(W, r1,r1+l, c1, c1+l): 
					done=True
					break
			if done: break
		if done: break
	if done: result = l
	else: result = 'IMPOSSIBLE'
				

	#OUTPUT
	if _jid_ < 0: print _t_, result
	g.write(_FMT_ %(_t_+1, str(result)))

if _jid_ >= 0: print 'Job %d finished *********************' %(_jid_)

