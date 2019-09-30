n=int(input())

x,y,h=[],[],[]
for i in range(n):
  a,b,c=map(int,input().split())
  x.append(a)
  y.append(b)
  h.append(c)

for i in range(n):
  if h[i]!=0:s=i;break

for cx in range(101):
  for cy in range(101):
    H=h[s]+abs(x[s]-cx)+abs(y[s]-cy)
    for i in range(n):
      if h[i]!=max(0,H-abs(x[i]-cx)-abs(y[i]-cy)):break
      if i==n-1:print(cx,cy,H);exit()