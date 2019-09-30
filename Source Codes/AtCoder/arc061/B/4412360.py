f=lambda:map(int,input().split())
h,w,n=f()
c=[(h-2)*(w-2)]+[0]*9
d={}
while n:
 n-=1;x,y=f()
 for i in range(9):a=x+i%3,y+i//3;g=h>=a[0]>2<a[1]<=w;t=d[a]=d.get(a,0)+g;c[t-g]-=1;c[t]+=1
print(*c)