N,L,T=map(int,input().split())
X=[0 for i in range(N)]
W=[0 for i in range(N)]
D=0
for i in range(N):
    X[i],W[i]=map(int,input().split())
    W[i]=-2*W[i]+3
    D+=(X[i]+T*W[i])//L
D%=N
Y=sorted([((T*W[i])+X[i])%L for i in range(N)])
for i in range(N):
    print(Y[(D+i)%N])