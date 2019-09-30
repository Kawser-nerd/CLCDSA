n=int(input())
baloon=[list(map(int, input().split())) for i in range(n)]
height=[b[0]+b[1]*(n-1) for b in baloon]
ans=0
def C(x):
    limit=[(x-b[0])/b[1] for b in baloon]
    limit=sorted(limit)
    if all (limit[i]-i>=0 for i in range(n)):
        return True
    return False
ub=10**16
lb=0
while ub-lb>1:
    mid=(lb+ub)//2
    if C(mid):
        ub=mid
    else:
        lb=mid
print(ub)