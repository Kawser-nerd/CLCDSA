n,m = (int(i) for i in input().split())
x,a,p = (int(i) for i in input().split())
s,ans = [],0
for i in range(n*m):
	s.append((x,i))
	x = (x+a)%p
s.sort()
for i in range(n):
	q = []
	for j in range(m):
		ans+=abs(s[i*m+j][1]//m-i)
		q.append(s[i*m+j][1]%m)
	q.sort()
	for i in range(m): ans+=abs(q[i]-i)
print(ans)