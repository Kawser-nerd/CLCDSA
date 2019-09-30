from collections import defaultdict
n,k = (int(i) for i in input().split())
p,q = [[] for i in range(n)],[]
for i in range(n-1):
	x,y,c = (int(i) for i in input().split())
	p[x-1].append((y-1,c))
	p[y-1].append((x-1,c))
for i,j in p[0]: q.append((i,j,0))
z,d = [-1]*n,defaultdict(int)
z[0],d[0],a = 0,1,0
while q:
	p0,p1,m = q.pop()
	z[p0] = z[m]^p1
	a+=d[k^z[p0]]
	d[z[p0]]+=1
	for i,j in p[p0]:
		if z[i]==-1: q.append((i,j,p0))
print(a)