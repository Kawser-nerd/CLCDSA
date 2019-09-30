n,m=map(int,input().split())
v=[0]*n
for _ in[0]*m:exec('v['+input().replace(' ','-1]+=1<<~-'))
d=[1]+[0]*(1<<n)
for i in range(1<<n):
 for j in range(n):
  if(i&1<<j)+(i&v[j])<1:d[i|1<<j]+=d[i]
print(d[-2])