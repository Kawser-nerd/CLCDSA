n = int(input())
s1 = input()
s2 = input()
par,rank = [i for i in range(n+1)],[0 for i in range(n+1)]
def root(x):
	if par[x]!=x: par[x] = root(par[x])
	return par[x]
def unite(x,y):
	x2,y2 = root(x),root(y)
	if x2!=y2:
		if rank[x2]<rank[y2]: par[x2] = y2
		else: par[y2] = x2
		if rank[x2]==rank[y2]: rank[x2]+=1
c,ans = [True for i in range(n)],1
for i in range(n):
	for j in range(n):
		if s1[i]==s1[j] or s2[i]==s2[j] or s1[i]==s2[j] or s2[i]==s1[j]: unite(i,j)
for i in range(n):
	if s1[i].isdigit() or s2[i].isdigit():
		for j in range(n):
			if root(i)==root(j): c[j]=False		
for i in range(n):
	if c[i]:
		if i==0: ans *= 9
		else: ans *= 10
		for j in range(n):
			if root(i)==root(j): c[j]=False
print(ans)