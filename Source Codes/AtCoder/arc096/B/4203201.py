n,c = map(int,input().split())
x = [0]
v = [0]
rf = [0] * (n+2)
rg = [0] * (n+2)
lf = [0] * (n+2)
lg = [0] * (n+2)
for i in range(0,n):
    X,V = map(int,input().split())
    x.append(X)
    v.append(V)
for i in range(0,n):
    rf[i+1] = rf[i] + v[i+1]
    rg[i+1] = max(rg[i],rf[i+1] - x[i+1])
for i in range(n+1,1,-1):
    lf[i-1] = lf[i] + v[i-1]
    lg[i-1] = max(lg[i],lf[i-1] - (c-x[i-1]))

ans = max(rg[n],lg[1])
for i in range(1,n):
    ans = max(ans,rg[i]+lg[i+1] - x[i],rg[i]+lg[i+1] - (c - x[i+1]))
print(ans)