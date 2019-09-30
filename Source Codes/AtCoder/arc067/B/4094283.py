N,A,B=map(int,input().split())
X=[int(i) for i in input().split()]
ans=0
for i in range(N-1):
    dist=X[i+1]-X[i]
    ans+=min(dist*A,B)
print(ans)