n,x = (int(i) for i in input().split())
h = [int(i) for i in input().split()]
s,ans = [[] for i in range(n+1)],0
for _ in range(n-1):
	a,b = (int(i) for i in input().split())
	s[a].append(b)
	s[b].append(a)
t,q,vis,p = 0,[x],[True]*(n+1),[0]*(n+1)
while q:
	t2 = q.pop()
	while p[t2]!=t:
		if h[t-1]: ans,h[p[t]-1] = ans+2,1
		t = p[t]
	vis[t],t = False,t2
	for i in s[t]:
		if vis[i]:
			p[i] = t
			q.append(i)
while t!=x:
	if h[t-1]: ans,h[p[t]-1] = ans+2,1
	t = p[t]
print(ans)