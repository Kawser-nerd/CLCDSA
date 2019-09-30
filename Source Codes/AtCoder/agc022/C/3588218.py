n = int(input())
a = [int(i) for i in input().split()]
b = [int(i) for i in input().split()]
x,ans = [],0
def f(m):
	q = [i+1 for i in range(m)]+x
	c = [[True]*51 for i in range(51)]
	for i in range(51): c[i][i] = False
	for i in q:
		for j in range(i,51): c[j][j%i] = False
	for k in range(51):
		for i in range(51):
			for j in range(51): c[i][j]*=bool(c[i][k]+c[k][j])
	return any(c[a[i]][b[i]] for i in range(n))
if f(50): print(-1)
else:
	for i in range(49,-1,-1):
		if f(i): x.append(i+1)
	for i in x: ans+=2**i
	print(ans)