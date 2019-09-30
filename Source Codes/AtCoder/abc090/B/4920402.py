a,b=map(int,input().split())
ans=0
for i in range(a,b+1):
  if str(i)==str(i)[::-1]:
    ans+=1
print(ans)