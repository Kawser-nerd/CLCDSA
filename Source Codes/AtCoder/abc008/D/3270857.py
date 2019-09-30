read=lambda :list(map(int,input().split()))
w,h=read()
n=int(input())
x,y=[0]*n,[0]*n
for i in range(n):
  x[i],y[i]=read()

d={}
def f(i,j,k,l):
  if (i,j,k,l) in d:
    return d[(i,j,k,l)]
  v=0
  for X,Y in zip(x,y):
    if i<X<=k and j<Y<=l:
      v=max(v,k-i+l-j-1+f(i,j,X-1,Y-1)+f(X,j,k,Y-1)+f(i,Y,X-1,l)+f(X,Y,k,l))
  d[(i,j,k,l)]=v
  return v

print(f(0,0,w,h))