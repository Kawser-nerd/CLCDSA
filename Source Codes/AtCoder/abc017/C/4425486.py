n,m=map(int,input().split())
imos=[0]*(m+2) #?????????
total=0
for i in range(n):
  l,r,s=map(int,input().split())
  imos[l]+=s
  imos[r+1]-=s
  total+=s
for i in range(m):
  imos[i+1]+=imos[i]
print(total-min(imos[1:-1]))