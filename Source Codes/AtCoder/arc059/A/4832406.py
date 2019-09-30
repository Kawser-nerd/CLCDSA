n=int(input())
l=list(map(int,input().split()))
s=sum(l)/n
if s-int(s)<int(s)+1-s:
  s=int(s)
else:
  s=int(s)+1
ans=0
for i in l:
  ans+=(s-i)**2
print(ans)