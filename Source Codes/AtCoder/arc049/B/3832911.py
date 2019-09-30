n=int(input())
X,Y,C=[],[],[]

for i in range(n):
    x,y,c=list(map(int,input().split()))
    X.append(x)
    Y.append(y)
    C.append(c)

def check(cost):
    le,ri=-10**5,10**5
    
    for x,c in zip(X,C):
        le=max(le,x-cost/c)
        ri=min(ri,x+cost/c)
        
    if le>ri:
        return False
    
    le,ri=-10**5,10**5
    
    for y,c in zip(Y,C):
        le=max(le,y-cost/c)
        ri= min(ri,y+cost/c)
        
    if le>ri:
        return False
    
    return True

le,ri=-1,(10**5)*(10**3)+1

for i in range(100):
    mid=(le+ri)/2
    
    if check(mid):
        ri=mid
        
    else:
        le=mid
        
print(ri)