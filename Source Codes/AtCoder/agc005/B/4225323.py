n = int(input())
a = [int(i) for i in input().split()]
b,l,r,ans = [0]*(n+1),[i for i in range(n+2)],[i for i in range(n+2)],0
for i in range(n): b[a[i]]=i
for i in range(n,0,-1):
	m = b[i]
	x,y = l[m],r[m]
	ans+=i*(m-x+1)*(y-m+1)
	l[y+1],r[x-1] = x,y
print(ans)