n,m,x,y=map(int,input().split())
xlist=list(map(int,input().split()))
xlist=sorted(xlist)
ylist=list(map(int,input().split()))
ylist=sorted(ylist)

flag=False
for i in range(x+1,y+1):
  if xlist[-1] < i <= ylist[0]:
    flag=True
    break
if flag:
  print('No War')
else:
  print('War')