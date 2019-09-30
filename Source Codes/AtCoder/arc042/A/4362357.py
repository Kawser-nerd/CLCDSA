N,M = map(int,input().split())
k = 0
L = []
for i in range(M):
  L.append(int(input()))
B = []
while k<N:
  B.append([float('inf'),False,k+1])
  k += 1
for i in range(len(L)-1,-1,-1):
  if B[L[i]-1][1] == False:
    B[L[i]-1][1] = True
    B[L[i]-1][0] = N-i
B.sort()
for i in range(N):
  print(B[i][2])