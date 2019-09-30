import math
n=int(input())
lmax=0
lx=[]
ly=[]
for i in range(n):
  x,y=map(int,input().split())
  lx.append(x)
  ly.append(y)
for i in range(n):
  for j in range(1,n):
    a=abs(lx[i]-lx[j])
    b=abs(ly[i]-ly[j])
    l=a*a+b*b
    if lmax<l:
      lmax=l
print(math.sqrt(lmax))