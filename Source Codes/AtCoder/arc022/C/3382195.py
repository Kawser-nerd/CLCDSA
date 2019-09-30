n = int(input())
x = [[] for i in range(n+1)]
for _ in range(n-1):
	a,b = (int(i) for i in input().split())
	x[a].append(b)
	x[b].append(a)
d,q,v = [0]*(n+1),[1],[1]*(n+1)
v[1] = 0
while q:
	p = q.pop()
	for i in x[p]:
		if v[i]:
			d[i],v[i] = d[p]+1,0
			q.append(i)
m = d.index(max(d))
d,q,v = [0]*(n+1),[m],[1]*(n+1)
v[m] = 0
while q:
	p = q.pop()
	for i in x[p]:
		if v[i]:
			d[i],v[i] = d[p]+1,0
			q.append(i)
print(m,d.index(max(d)))