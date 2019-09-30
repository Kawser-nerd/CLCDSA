import math
N=int(input())

a=[0]*(N+1)
for i in range(1,N+1):
    k=[a[i-1]]
    for j in range(1,10):
        x=i-6**j
        if x<0: break
        k.append(a[x])
        
    for j in range(1,10):
        x=i-9**j
        if x<0: break
        k.append(a[x])
    
    a[i]=min(k)+1


print(int(a[N]))