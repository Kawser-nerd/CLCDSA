def rl():
	return map(int,raw_input().split())

def go(v,sample):
	res = 0
	for x in sample:
		if v==x:
			res += 1
	#print 'res',v,sample,res
	return res*1.0/len(sample)
	
def solve(r,n,m,k,sample):
	# assume r=100,n=3,m=5,k=7
	best_s = []
	best_p = -1
	#print sample
	for a in range(2,m+1):
		for b in range(2,m+1):
			for c in range(2,m+1):
				s = [a,b,c]
				ps = [1,a,b,c,a*b,b*c,c*a,a*b*c]
				p = 0
				bad = False
				for v in sample:
					if v not in ps:
						bad = True
				if bad:
					continue
				for v in ps:
					p += 1.0/8*go(v,sample)
				#print s,ps,sample,p
				if p > best_p:
					best_p = p
					best_s = s
	print ''.join(map(str,best_s))

	
def main():
	(T,) = rl()
	for t in range(1,T+1):
		r,n,m,k = rl()
		samples =[]
		for i in range(r):
			samples.append(rl())
		print 'Case #%d:'%(t)
		for sample in samples:
			solve(r,n,m,k,sample)
		

main()