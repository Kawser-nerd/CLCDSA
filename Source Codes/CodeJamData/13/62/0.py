T = int(raw_input())
for caseID in range(1,T+1):
	n = int(raw_input())
	aa = map(int,raw_input().split())
	answer = 1e9
	for i in range(n):
		for j in range(i+1,n):
			a = float(aa[j]-aa[i]) / float(j-i)
			l = 0
			r = 1e9
			for iter in range(70):
				m = (l + r) / 2.0
				# T[i] - aa[i] <= m for i=0..n-1
				bmin, bmax = -1e9, 1e9
				for k in range(n):
					# abs(a*k+b - aa[k]) <= m
					# aa[k]-m <= a*k+b <= aa[k]+m
					# b >= aa[k]-m-a*k
					# b <= aa[k]+m-a*k
					bmin = max(bmin, aa[k]-m-a*k)
					bmax = min(bmax, aa[k]+m-a*k)
				if bmin <= bmax:
					r = m
				else:
					l = m
			answer = min(answer, l)
	print "Case #%d: %.9f" % (caseID, answer)
			
