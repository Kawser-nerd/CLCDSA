import math

A=list(map(int,input().split()))
M=[0]*A[0]
for i in range(A[0]):
    M[i]=int(input())
S=math.floor((A[1]-sum(M))/min(M))
print(S+A[0])