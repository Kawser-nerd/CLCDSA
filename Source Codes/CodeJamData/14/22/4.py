def solve(A, B, K):
	r = 0
	for a in range(32):
	 if A>>a&1:
		for b in range(32):
		 if B>>b&1:
			for k in range(32):
			 if K>>k&1:
				t = 1
				for i in range(32):
					if i<k:
						if i<a and i<b:
							t *= 4
						elif i<a or i<b:
							t *= 2
						else:
							t *= 1
					else:
						x = K>>i&1
						if i==k:
							x = 0
						if i<a and i<b:
							t *= [3, 1][x]
						elif i<a or i<b:
							if i<a:
								y = 0 if i==b else B>>i&1
							else: # i<b
								y = 0 if i==a else A>>i&1
							if x==0 and y==0:
								t *= 2
							elif x==0 and y==1:
								t *= 1
							elif x==1 and y==0:
								t *= 0
							elif x==1 and y==1:
								t *= 1
						else:
							y = (0 if i==a else A>>i&1) & (0 if i==b else B>>i&1)
							if x==y:
								t *= 1
							else:
								t *= 0
				r += t
	return r

for t in range(input()):
	A, B, K = map(int, raw_input().split())
	print "Case #%s: %s" % (t+1, solve(A,B,K))
