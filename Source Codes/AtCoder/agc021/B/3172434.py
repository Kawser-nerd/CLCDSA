from math import sqrt,pi,acos
n = int(input())
p1 = [[int(i) for i in input().split()] for i in range(n)]
p,q,ans = sorted(p1),[],[]
x1,x2,y1,y2,z1,z2 = p[0][0],p[0][1]+1,p[0][0],p[0][1],10**6+1,0
def cos(a,b,c,d,e,f):
	a,b,e,f = a-c,b-d,e-c,f-d
	return (a*e+b*f)/(sqrt(a**2+b**2)*sqrt(e**2+f**2))
while p[0]!=[z1,z2]:
	q.append([y1,y2])
	num = 2
	for i,j in p:
		if y1!=i or y2!=j:
			m = cos(x1,x2,y1,y2,i,j)
			if num>m: num,z1,z2 = m,i,j
	ans.append((pi-acos(max(-1,num)))/(2*pi))
	x1,x2,y1,y2 = y1,y2,z1,z2
ans = [(pi-acos(cos(x1,x2,y1,y2,q[1][0],q[1][1])))/(2*pi)]+ans[1:]
for i in p1:
	if i in q: print(ans[q.index(i)])
	else: print(0)