n,m = (int(i) for i in input().split())
x,y,dp = [[] for i in range(n)],[],[[0,-1] for i in range(n)]
for i in range(m):
	a,b = (int(i)-1 for i in input().split())
	x[a].append(b)
	x[b].append(a)
q = int(input())
for i in range(q):
	v,d,c = (int(i) for i in input().split())
	y.append((v-1,d,c))
def f(v,d,c):
	z,z2 = dp[v]
	if d>z2:
		if z: dp[v] = z,d
		else: dp[v] = c,d
		if d:
			for i in x[v]: f(i,d-1,c)
for i,j,k in y[::-1]: f(i,j,k)
for i in dp: print(i[0])