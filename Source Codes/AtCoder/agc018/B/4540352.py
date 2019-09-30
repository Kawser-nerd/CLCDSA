n,m=map(int,input().split())
k=[[0]*m for i in range(n)]
for i in range(n):
    k[i]=list(map(int,input().split()))
ans=1000
for i in range(m-1):
    ma=[0]*m
    mi=-1
    for j in range(n):
        ma[k[j][0]-1]+=1
    if ans>max(ma):
        ans=max(ma)
    mi=ma.index(max(ma))+1
    for j in range(n):
        k[j].remove(mi)
if m==1:
    print(n)
else:
    print(ans)