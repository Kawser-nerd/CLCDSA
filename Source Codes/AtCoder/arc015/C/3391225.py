import sys
sys.setrecursionlimit(1000)
n = int(input())
x,y,z,num,n1,n2 = set(),{},{},1,0,float("inf")
def gcd(a,b):
	if a%b: return gcd(b,a%b)
	else: return b
for _ in range(n):
	l,m,s = (i for i in input().split())
	m = int(m)
	if l in x and s in x:
		if z[s]-z[l]:
			g = gcd(y[l]*m,y[s])
			gl,gs,zs = y[s]//g,y[l]*m//g,z[s]
			for i,j in z.items():
				if j==zs: y[i],z[i] = y[i]*gs,z[l]
				elif j==z[l]: y[i]*=gl
	elif l in x: y[s],z[s] = y[l]*m,z[l]
	elif s in x:
		g = m//gcd(y[s],m)
		if g-1:
			for i,j in z.items():
				if j==z[s]: y[i]*=g
		y[l],z[l] = y[s]//m,z[s]
	else: y[l],y[s],z[l],z[s],num = 1,m,num,num,num+1
	x.add(l)
	x.add(s)
for i,j in y.items():
	if n1<j: a1,n1 = i,j
	if n2>j: a2,n2 = i,j
print("1"+a2+"="+str(n1//n2)+a1)