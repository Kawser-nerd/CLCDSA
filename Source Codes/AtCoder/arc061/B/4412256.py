f=lambda:map(int,input().split())
h,w,n=f()
d={}
while n:
 n-=1;x,y=f()
 for i in range(9):a=(x+i%3,y+i//3);d[a]=d.get(a,0)+(h>=a[0]>2<a[1]<=w)
c=[list(d.values()).count(i+1)for i in range(9)]
print((h-2)*(w-2)-sum(c),*c)