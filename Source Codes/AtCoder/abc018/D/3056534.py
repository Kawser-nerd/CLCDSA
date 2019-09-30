from itertools import combinations
n,m,p,q,r = (int(i) for i in input().split())
c,ans = [[0 for i in range(m)] for i in range(n)],0
for _ in range(r):
	x,y,z = (int(i) for i in input().split())
	c[x-1][y-1] = z
for i in combinations(range(n),p):
	d = [0]*m
	for j in i:
		for k in range(m): d[k]+=c[j][k] 
	ans = max(ans,sum(sorted(d)[m-q:]))
print(ans)