I=lambda:map(int,input().split());n,m=I();v=[0]*n;d=[1]+[0]*(1<<n)
for _ in[0]*m:s,g=I();v[s-1]+=1<<g-1
for i in range(1<<n):
 for j in range(n):
  if(i&1<<j)+(i&v[j])<1:d[i|1<<j]+=d[i]
print(d[-2])