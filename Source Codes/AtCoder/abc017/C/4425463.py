n,m=map(int,input().split())
imos=[0]*(m+1) #?????????
t=0
for i in range(n):
  l,r,s=map(int,input().split())
  imos[l-1]+=s
  imos[r]-=s
  t+=s
for i in range(m):
  imos[i+1]+=imos[i]
print(t-min(imos[:-1]))