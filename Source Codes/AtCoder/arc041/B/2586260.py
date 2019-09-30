N,M=map(int,input().split())
B=[list(map(int,input()))for _ in[0]*N]
A=[[0]*M for _ in[0]*N]
for i in range(1,N-1):
 for j in range(1,M-1):
  A[i][j]=B[i-1][j]-A[i-1][j+1]-A[i-1][j-1]-A[i-2][j]
for a in A:print(*a,sep='')