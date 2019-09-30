n,m,l = map(int,input().split())
p,q,r = map(int,input().split())
res = 0
for a,b,c in [[p,q,r],[p,r,q],[q,p,r],[q,r,p],[r,p,q],[r,q,p]]:
    res = max(res, (n//a) * (m//b) * (l//c))
print(res)