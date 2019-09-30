#debug 
def pr(*a):
	return
	for x in a: print x,
	print

def maxcan(C,ds):
	m = [0]*len(ds)
	if ds[0] == 1:
		m[0] = C
	else:
		return 0
	
	for i in range(1,len(ds)):
		d = ds[i]
		if d > m[i-1]+1:
			return m[i-1]
		else:
			m[i] = C*d+m[i-1]
	return m[-1]
		
	
def solve(C,ds,V):
	mx = maxcan(C,ds)
	newd = 0
	while mx < V:
		ds.append(mx+1)
		ds.sort()
		pr(ds)
		newd += 1
		mx = maxcan(C,ds)
	return newd
	
import sys
f = open(sys.argv[1])
out_fname = sys.argv[1][:-2] + "out"
out = open(out_fname,"w")
T = int(f.readline().strip())

for tc in range(1, T+1):
	C,D,V = [int(x) for x in f.readline().strip().split()]
	pr(C,D,V)
	ds = [int(x) for x in f.readline().strip().split()]
	pr(ds)
	assert len(ds)==D
	rt = solve(C,ds,V)
	pr("Case #%d: %s"%(tc, str(rt)))
	pr("="*20)
	print >>out, "Case #%d: %s"%(tc, str(rt))

out.close()