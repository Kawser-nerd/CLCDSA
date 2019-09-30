def ceil(a,b):
    return -((-a)//b)
def floor(a,b):
    return a//b
K=int(input())
A=[int(i) for i in input().split()]
L=[0 for i in range(K+1)]
R=[0 for i in range(K+1)]
L[K]=2
R[K]=2
for i in range(1,K+1)[::-1]:
    L[i-1]=ceil(L[i],A[i-1])*A[i-1]
    R[i-1]=floor(R[i],A[i-1])*A[i-1]+A[i-1]-1
if L[0]<=R[0]:
    print(L[0],R[0])
else:
    print(-1)