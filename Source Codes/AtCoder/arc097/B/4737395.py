n,m=map(int,input().split())
p=list(map(int,input().split()))
k=[i for i in range(n+1)]
r=[0]*(n+1)
def root(x):
    if x==k[x]:
        return x
    x=k[x]
    return root(k[x])
def unite(x,y):
    x=root(x)
    y=root(y)
    if x!=y:
        if r[x]>r[y]:
            k[y]=x
            r[x]+=1
        else:
            k[x]=y
            r[y]+=1
c=0
for i in range(m):
    x,y=map(int,input().split())
    unite(x,y)
for i in range(n):
    if root(i+1)==root(p[i]):
        c+=1
print(c)