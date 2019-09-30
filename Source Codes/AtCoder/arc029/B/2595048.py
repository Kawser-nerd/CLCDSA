from math import sqrt,atan,sin,cos
a,b = (int(i) for i in input().split())
n = int(input())
a,b = min(a,b),max(a,b)
ab,th = sqrt(a**2+b**2),atan(a/b)
for _ in range(n):
	c,d = (int(i) for i in input().split())
	c,d = min(c,d),max(c,d)
	if a<=c and b<=d: ans = "YES"
	else:
		hi,lo = atan(b/a),0
		for i in range(100):
			mid = (hi+lo)/2
			if ab*sin(mid+th)<=d: lo=mid
			else: hi = mid
		if ab*cos(lo-th)<=c: ans = "YES"
		else: ans = "NO"
	print(ans)