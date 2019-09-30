#debug 
def pr(*a):
	return
	for x in a: print x,
	print

def maxOverlap(word):
	m = 0
	for i in range(len(word)):
		if word.endswith(word[:i]):
			m = i
	return m
	
def solve(ks, target, limit):
	for c in target:
		if c not in ks:
			return 0.0
	tail = len(target)-maxOverlap(target)
	bring = 1 + (limit-len(target))//tail
	d = {}
	for c in ks:
		d[c] = d.get(c, 0)+1
	e = 1.0
	for c in target:
		e = e*d[c]/len(ks)
	give = (limit+1-len(target))*e
	return bring-give
	
import sys
f = open(sys.argv[1])
out_fname = sys.argv[1][:-2] + "out"
out = open(out_fname,"w")
T = int(f.readline().strip())

for tc in range(1, T+1):
	K,L,S = [int(x) for x in f.readline().strip().split()]
	pr(K,L,S)
	ks = f.readline().strip()
	pr(ks)
	assert len(ks)==K
	target = f.readline().strip()
	pr(target)
	assert len(target)==L
	rt = solve(ks, target, S)
	pr("Case #%d: %s"%(tc, str(rt)))
	pr("="*20)
	print >>out, "Case #%d: %s"%(tc, str(rt))

out.close()