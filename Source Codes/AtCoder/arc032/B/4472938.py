def r(x):
 while u[x]>=0:x=u[x]
 return x  
(n,m),*e=[map(int,t.split())for t in open(0).readlines()]
u=[-1]*-~n
for x,y in e:
 x,y=sorted((r(x),r(y)))
 if x<y:u[x]+=u[y];u[y]=x
print(sum(i<0for i in u)-2)