n=int(input())
a=list(map(int,input().split()))
m=round(sum(a)/n)
ans=0
for i in range(n):
  ans+=(a[i]-m)**2
print(ans)