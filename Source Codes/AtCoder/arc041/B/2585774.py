N,M=map(int,input().split())
B=[list(map(int,input()))for _ in[0]*N]
A=[[0]*M for _ in[0]*N]
for x in range(N-2):
 for y in range(M):
  if B[x][y]:
   A[x+1][y]=t=B[x][y]
   for u,v in[(0,0),(1,-1),(1,1),(2,0)]:B[x+u][y+v]-=t
for a in A:print(*a,sep='')