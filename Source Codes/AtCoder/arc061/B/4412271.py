f=lambda:map(int,input().split())
h,w,n=f()
d={}
while n:
 n-=1;x,y=f()
 for i in range(9):
  a=(x+i%3,y+i//3)
  if h>=a[0]>2<a[1]<=w:d[a]=d.get(a,0)+1
c=[0]*9
for i in d:c[d[i]-1]+=1
print((h-2)*(w-2)-sum(c),*c)