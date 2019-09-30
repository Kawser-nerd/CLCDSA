n=int(input())
l=list(map(int,input().split()))
l.sort(reverse=1)
ans=0
for i in range(n):
  ans+=l[2*i+1]
print(ans)