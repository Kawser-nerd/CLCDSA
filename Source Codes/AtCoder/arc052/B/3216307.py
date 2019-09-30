import math
N,Q=map(int,input().split())
X=[0 for i in range(N)]
R=[0 for i in range(N)]
H=[0 for i in range(N)]
A=[0 for i in range(Q)]
B=[0 for i in range(Q)]
for i in range(N):
    X[i],R[i],H[i]=map(int,input().split())
for i in range(Q):
    A[i],B[i]=map(int,input().split())
M=2*10**4
T=[0 for i in range(M)]
for i in range(N):
    CST=math.pi*R[i]**2/(3*H[i]**2)
    for k in range(H[i]):
        T[X[i]+k]+=CST*((k+1-H[i])**3-(k-H[i])**3)
S=[0 for i in range(M+1)]
for i in range(M):
    S[i+1]=S[i]+T[i]
for i in range(Q):
    print(S[B[i]]-S[A[i]])