import sys

for test in range(input()):
	B,N = map(int,raw_input().split())
	X = map(int,raw_input().split())
	X += [0]*(37-len(X))
	X.sort()
	ans = 0
	for i in range(2001):
		for j in range(37):
			if X[j]>i:
				continue
			a = 0
			b = 0
			for k in range(j+1):
				a += i-X[k]
				b += 36.*(i-X[k])/(j+1)
			for k in range(j+1,37):
				a += max(0,(i+1)-X[k])
			if a<=B:
				ans = max(ans, b-a)
	print "Case #%s: %.20f"%(test+1,ans)
	sys.stdout.flush()

