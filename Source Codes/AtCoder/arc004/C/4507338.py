import sys
def myin():
    for s in sys.stdin:
        for t in s.split():
            yield t
##
_in=myin()
X,Y=next(_in).split('/')
X,Y=int(X),int(Y)
##
def check(v):
    return Y*(v-1) > 2*X
##
l,r=0,int(2e18)+10
while r-l>1:
    m=l+(r-l)//2
    if check(m):
        r=m
    else:
        l=m
r
##
possibles=[r-2,r-1]
##
def ok(n):
    if (n*X)%Y != 0:
        return 0
    M=n*(n+1)//2-(n*X)//Y
    if M<1 or M > n:
        return 0
    return M
ans=[]
for i in possibles:
    M=ok(i)
    if M!=0:
        ans.append([i,M])
if ans:
    for i,M in ans:
        print("%d %d"%(i,M))
else:
    print("Impossible")
##