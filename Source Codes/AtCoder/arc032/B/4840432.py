n,m=map(int,input().split())
s=[i for i in range(n+1)]
d=[1]*(n+1)
def root(x):
    if x==s[x]:
        return x
    x=s[x]
    return root(s[x])
def unite(x,y):
    x=root(x)
    y=root(y)
    if x!=y:
        if d[x]<d[y]:
            s[x]=y
            d[y]+=1
        else:
            s[y]=x
            d[x]+=1
for i in range(m):
    a,b=map(int,input().split())
    unite(a,b)
for i in range(1,n+1):
    s[i]=root(i)
print(len(list(set(s[1:])))-1)