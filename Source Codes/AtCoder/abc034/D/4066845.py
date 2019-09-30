n,k=map(int,input().split())
w=[0]*n
p=[0]*n
for i in range(n):
    w[i],p[i] = map(int,input().split())

lb=0
ub=1

def ok(per):
    salt = [w[i]*(p[i]/100 - per) for i in range(n)]
    salt.sort()
    salt.reverse()
    return sum(salt[:k])>=0

while ub-lb>0.00000001:
    mid=lb+(ub-lb)/2
    if(ok(mid)):
        lb=mid
    else:
        ub=mid
    
print(lb*100)