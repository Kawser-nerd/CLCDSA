n,x=map(int,input().split())
a=list(map(int,input().split()))
a.sort()
a.reverse()
ans=0
while x>0:
  if x==0:
    break
  elif len(a)==0:
    ans-=1
    break
  if a[-1]<=x:
    x-=a.pop()
    ans+=1
  else:
    break
print(ans)