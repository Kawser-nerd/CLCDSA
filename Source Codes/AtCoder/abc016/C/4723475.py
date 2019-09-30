n,m = map(int,input().split())
d = [[float("inf")]*n for i in range(n)]
for i in range(m):
	a,b = map(int,input().split())
	a -= 1
	b -= 1
	d[a][b] = 1
	d[b][a] = 1
for i in range(n):
	for j in range(n):
		for k in range(n):
			d[i][j] = min(d[i][j],d[i][k]+d[k][j])
for i in d:
	print(max(0,i.count(2)-1))