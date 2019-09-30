from math import pi
n,q = (int(i) for i in input().split())
v = [0 for i in range(2*(10**4)+2)]
for _ in range(n):
	x,r,h = (int(i) for i in input().split())
	num = (r/h)**2
	for i in range(x+h,x,-1): v[i] += num*((x+h-i+1)**3-(x+h-i)**3)
for i in range(2*(10**4)+2): v[i]+=v[i-1]
for _ in range(q):
	a,b = (int(i) for i in input().split())
	print((v[b]-v[a])*pi/3)