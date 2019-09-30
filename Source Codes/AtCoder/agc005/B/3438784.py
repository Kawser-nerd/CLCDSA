N=int(input())
a=[0]+[int(i) for i in input().split()]
par=[0 for i in range(N+1)]
size=[0 for i in range(N+1)]
def find(x):
    if (par[x]==x):
        return x
    par[x]=find(par[x])
    return par[x]
def unite(x,y):
    x=find(x)
    y=find(y)
    res=size[x]*size[y]
    size[x]+=size[y]
    par[y]=x
    return res
for i in range(N+1):
    par[i]=i
    size[i]=1
b=[0 for i in range(N+1)]
for i in range(N+1):
    b[a[i]]=i
ans=0
for j in range(1,N+1)[::-1]:
    i=b[j]
    ans+=a[i]
    if i-1>=1 and a[i-1]>a[i]:
        ans+=unite(i-1,i)*a[i]
    if i+1<=N and a[i+1]>a[i]:
        ans += unite(i+1,i)*a[i]
print(ans)