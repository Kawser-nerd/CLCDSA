w,h,n=map(int,input().split())
wlist=[0]*w
hlist=[0]*h
for _ in range(n):
  x,y,a=map(int,input().split())
  if a==1:
    for i in range(x):
      wlist[i]=1
  elif a==2:
    for i in range(x,w):
      wlist[i]=1
  elif a==3:
    for i in range(y):
      hlist[i]=1
  elif a==4:
    for i in range(y,h):
      hlist[i]=1
print(wlist.count(0)*hlist.count(0))