INF=10**17

def solve(n,q,se,dists,uv,debug):
	shortest = [[INF for i in xrange(n)] for j in xrange(n)]
	for i in xrange(n):
		for j in xrange(n):
			if(dists[i][j]!=-1):
				shortest[i][j]=dists[i][j]
	for k in xrange(n):
		for i in xrange(n):
			for j in xrange(n):
				shortest[i][j]=min(shortest[i][j],shortest[i][k]+shortest[k][j])

	def best(i,j):
		if(shortest[i][j]<= se[i][0]):
			return float(shortest[i][j])/se[i][1]
		return INF
	actual = [[best(i,j) for j in xrange(n)] for i in xrange(n)]
	for k in xrange(n):
		for i in xrange(n):
			for j in xrange(n):
				actual[i][j]=min(actual[i][j],actual[i][k]+actual[k][j])
	ans=[actual[uv[i][0]-1][uv[i][1]-1] for i in xrange(q)]
	return ' '.join(map(str,ans))

T = int(input())
for case in range(1,T+1):
	n,q=map(int,raw_input().split())
	se = [map(int,raw_input().split()) for i in xrange(n)]
	dists = [map(int,raw_input().split()) for i in xrange(n)]
	uv = [map(int,raw_input().split()) for i in xrange(q)]
	debug=False
	print("Case #{}: {}".format(case, solve(n,q,se,dists,uv,debug)))
