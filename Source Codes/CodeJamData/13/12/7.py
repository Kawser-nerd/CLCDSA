def rl():
	return map(int,raw_input().split())

def dfs(e,r,n,v,i,c,g):
	if i==n:
		return g
	res = 0
	for x in range(c+1):
		if c-x+r<=e:
			res=max(res,dfs(e,r,n,v,i+1,min(c-x+r,e),g+x*v[i]))
	return res

def solve(e,r,n,v):
	r=min(e,r)
	ans = dfs(e,r,n,v,0,e,0)
	return ans
	
def main():
	(T,) = rl()
	for t in range(1,T+1):
		e,r,n = rl()
		v = rl()
		ans = solve(e,r,n,v)
		print 'Case #%d: %d'%(t,ans)

main()