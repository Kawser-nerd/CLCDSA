R,B=map(int,input().split())
x,y=map(int,input().split())
f=lambda k:k<=(R-k)//(x-1)+(B-k)//(y-1)

l,r=0,min(R,B)+1
while r-l>1:
  m=(r+l)//2
  if f(m):
    l=m
  else:
    r=m
print(l)