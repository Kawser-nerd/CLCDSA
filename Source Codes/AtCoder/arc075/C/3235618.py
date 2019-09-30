n,k = (int(i) for i in input().split())
a = [int(input())-k for i in range(n)]
b = [[0,0]]
for i in range(n): b.append([b[-1][0]+a[i],i+1])
b.sort()
num,c = 1,[[b[0][1],1]]
for i in range(1,n+1):
	if b[i][0]!=b[i-1][0]: num+=1
	c.append([b[i][1],num])
c,d,ans = sorted(c),[0]*(n+2),0
def add(i):
	while i<=n+1:
		d[i] += 1
		i += i & -i
def get(i):
	s = 0
	while i:
		s += d[i]
		i -= i & -i
	return s
for i,j in c:
	ans+=get(j)
	add(j)
print(ans)