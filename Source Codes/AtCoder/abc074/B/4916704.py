n=int(input())
k=int(input())
x=list(map(int,input().split()))
ans=0
for i in range(n):
  ans+=min(x[i],k-x[i])
print(ans*2)