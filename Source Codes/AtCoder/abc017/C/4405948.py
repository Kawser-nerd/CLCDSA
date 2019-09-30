N,M = map(int,input().split())
L = []
S = 0
for i in range(N):
  L.append(list(map(int,input().split())))
P = [0]*(M+1)
for j in range(N):
  P[L[j][0]-1] += L[j][2]
  P[L[j][1]] -= L[j][2]
for k in range(M):
  P[k+1] = P[k+1]+P[k]
for l in range(N):
  S += L[l][2]
P.sort()
print(S-P[1])