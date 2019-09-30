n, k = map(int, input().split())
wp=[list(map(int, input().split())) for i in range(n)]
def C(x):
    wp1=[(wpi[1]-x)*wpi[0] for wpi in wp]
    wp1.sort()
    if sum(wp1[n-k:])>=0:
        return True
    return False
ub=100
lb=0
for i in range(100):
    mid=(ub+lb)/2
    if C(mid):
        lb=mid
    else:
        ub=mid
print(ub)