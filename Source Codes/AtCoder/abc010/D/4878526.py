n,g,e=map(int,input().split())
p=list(map(int,input().split()))
s=[[0]*(n+1)for i in range(n+1)]
for i in p:
    s[i][n]=1
for i in range(e):
    a,b=map(int,input().split())
    s[a][b]=1
    s[b][a]=1
def f(x):
    v[x]=True
    if x==n:
        return True
    for i in range(n+1):
        if not v[i] and s[x][i]>0:
            if f(i):
                s[x][i]-=1
                s[i][x]+=1
                return True
    return False
a=0
while n:
    v=[False]*(n+1)
    if f(0):
        a+=1
    else:
        break
print(a)