a,b=map(int,input().split())
x=abs(a-b)
ans=0
if x>7:
  ans+=1+((x-8)//10)
  x=abs(x-ans*10)
if 3<x:
  ans+=1
  x=abs(x-5)
ans+=x
print(ans)