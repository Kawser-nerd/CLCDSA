n,m = (int(i) for i in input().split())
x = []
for _ in range(n):
	b,c = input(),[]
	for i in b: c.append(int(i))
	x.append(c)
ans = [[0 for i in range(m)] for i in range(n)]
for i in range(n):
	for j in range(m):
		if x[i][j]==0: continue
		ans[i+1][j] = x[i][j]
		for k,k2 in [[i+1,j-1],[i+1,j+1],[i+2,j],[i,j]]: x[k][k2] -= x[i][j]
for i in ans:
	s = ""
	for j in i: s += str(j)
	print(s)