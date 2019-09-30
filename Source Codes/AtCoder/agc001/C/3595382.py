from collections import deque
n,k = (int(i) for i in input().split())
b = [[int(i)-1 for i in input().split()] for i in range(n-1)]
x,d,ans,c = [[] for i in range(n)],[[] for i in range(n)],n,0
for i,j in b:
	x[i].append(j)
	x[j].append(i)
def f(s):
	for i in range(n):
		q,v = deque(),[1]*n
		v[i] = 0
		for j in x[i]:
			q.append((j,1,j))
			d[i].append(j)
			v[j] = 0
		while q:
			p = q.pop()
			if p[1]<s:
				for j in x[p[0]]:
					if v[j]:
						q.append((j,p[1]+1,p[2]))
						d[i].append(p[2])
						v[j] = 0
if k>n//2:
	for i in x: c = max(len(i),c)
if n-c+1<=k: ans = 0
elif k==1: ans = n-2
else:
	f(k//2)
	if k%2:
		for i,j in b: ans = min(ans,n-len(d[i])-len(d[j])+d[i].count(j)+d[j].count(i)-2)
	else:
		for i in range(n): ans = min(ans,n-len(d[i])-1)
print(ans)