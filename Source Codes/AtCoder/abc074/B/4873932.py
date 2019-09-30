n=int(input())
k=int(input())
xl=[int(i) for i in input().split()]
ans=0
for i in range(n):
  ans+=min(2*abs(xl[i]),2*abs(k-xl[i]))
print(ans)