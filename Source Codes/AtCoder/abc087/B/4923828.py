import math
A=int(input())
B=int(input())
C=int(input())
X=int(input())

ans=0
a=math.floor(X/500)
for i in range(min(A,a)+1):
    X2=X-500*i
    b=math.floor(X2/100)
    for j in range(min(B,b)+1):
        X3=X2-100*j
        if X3%50==0:
            c=X3/50
            if c<=C:
                ans+=1
            else:
                continue
        else:
            continue
print(ans)