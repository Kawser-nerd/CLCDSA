n,k=map(int,input().split())
l=sorted([int(input()) for i in range(n)])
ans=1000000000
for i in range(n-k+1):
	ans=min(l[i+k-1]-l[i],ans)
print(ans)