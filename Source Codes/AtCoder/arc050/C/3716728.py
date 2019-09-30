import numpy as np
from fractions import gcd
A,B,M=map(int,input().split())
D=gcd(A,B)
X=np.array([[10,1],[0,1]])
Y=np.array([[pow(10,D,M),1],[0,1]])
x=np.array([0,1])
def f(a,A):
    T=np.array([[1,0],[0,1]])
    U=A
    s=a
    while s!=0:
        if s%2==1:
            T=np.dot(T,U)
            T=T%M
        U=np.dot(U,U)
        U=U%M
        s=s//2
    return T%M
print(((np.dot(f(A,X),x))[0]*np.dot(f(B//D,Y),x)[0])%M)