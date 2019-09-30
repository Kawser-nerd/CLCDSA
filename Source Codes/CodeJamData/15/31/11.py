#debug 
def pr(*a):
	return
	for x in a: print x,
	print

def solve(R,C,W):
	res = (R-1)*(C//W)
	x = C//W
	if C%W==0:
		res += x-2+W+1
	else:
		res += x-1+W+1
	return res
	
import sys
f = open(sys.argv[1])
out_fname = sys.argv[1][:-2] + "out"
out = open(out_fname,"w")
T = int(f.readline().strip())

for tc in range(1, T+1):
	R,C,W = [int(x) for x in f.readline().strip().split()]
	pr(R,C,W)
	rt = solve(R,C,W)
	pr("Case #%d: %s"%(tc, str(rt)))
	pr("="*20)
	print >>out, "Case #%d: %s"%(tc, str(rt))

out.close()