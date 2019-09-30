from datetime import *
n=int(input())
a=[]
for i in range(n):
  m,d=map(int,input().split('/'))
  a+=[date(2012,m,d)]
d=date(2012,1,1)
r=0
s=0
c=0
while d.year==2012:
  if d.weekday() in (5,6) or d in a:
    s+=1
    if d.weekday() in (5,6) and d in a:
      c+=1
  elif c>0:
    s+=1
    c-=1
  else:
    s=0
  r=max(r,s)
  d+=timedelta(days=1)
print(r)