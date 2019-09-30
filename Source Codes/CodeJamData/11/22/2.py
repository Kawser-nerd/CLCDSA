class empty: pass;

def check(C,D,V,t):
	p = -(10**100)
	for v in V:
		w = D*v.V
		r = t - D*(v.V-1)/2
		if r<0 or p+w/2-v.P>r:
			return False
		p = max(v.P-r+w/2,p+w)
	return True

T = input()
for case in range(1,T+1):
	C,D = map(int,raw_input().split())
	D *= 2
	V = []
	for i in range(C):
		t = map(int,raw_input().split())
		V += [empty()]
		V[-1].P = t[0]*2
		V[-1].V = t[1]
	
	#for t in range(10):
	#	print t, check(C,D,V,t)
	l = 0
	r = 10**100
	while (r-l>1):
		m = (l+r)/2
		if check(C,D,V,m):
			r = m
		else:
			l = m
	if check(C,D,V,0):
		r = 0
	print "Case #%s: %.1f" % (case,r*0.5)
	
		