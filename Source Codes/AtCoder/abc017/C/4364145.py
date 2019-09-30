N,M=map(int,input().split())
l=[0 for i in range(N)]
r=[0 for i in range(N)]
s=[0 for i in range(N)]
X=[0 for i in range(M)]
S=0
for i in range(N):
  l,r,s=map(int,input().split())
  l-=1;r-=1
  if 0<=l<M:
    X[l]+=s
  if 0<=r+1<M:
    X[r+1]-=s
  S+=s
A=[0 for i in range(M)]
A[0]=X[0]
for i in range(1,M):
  A[i]=X[i]+A[i-1]
print(S-min(A))