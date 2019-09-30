n,m = (int(i) for i in input().split())
a = [[int(i) for i in input().split()] for i in range(n)]
b,x,num = [0]*n,[0]*(m+1),m
for i in range(n): x[a[i][0]]+=1
z = max(x)
ans,x[x.index(z)] = z,-1
while ans>(n-1)//num+1:
	for i in range(n):
		if x[a[i][b[i]]]==-1:
			while x[a[i][b[i]]]==-1: b[i]+=1
			x[a[i][b[i]]]+=1
	z = max(x)
	ans,x[x.index(z)],num = min(ans,z),-1,num-1
print(ans)