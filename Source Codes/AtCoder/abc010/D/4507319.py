# ?????????????
def DFS(L, s, t):
  S = [[s, 0]]
  P = [0] * T
  D = [0] * len(L)
  while S != []:
    k = S.pop()
    P[k[1]] = k[0]
    if L[k[0]][T - 1] > 0:
      P[k[1] + 1] = T - 1
      return P
    for i in range(len(L)):
      if D[i] == 0 and L[k[0]][i] > 0:
        S.append([i, k[1] + 1])
        D[i] = 1
  return False 

from collections import deque
N, G, E = list(map(int, input().split()))
p = list(map(int, input().split()))
ab = [list(map(int, input().split())) for i in range(E)]

T = N + 1
Data = [[0] * T for i in range(T)]
L = [[0] * T for i in range(T)]

for i in ab:
  Data[i[0]][i[1]] = 1
  Data[i[1]][i[0]] = 1

Q = deque([0])
F = [0] * T

# ????
while len(Q) > 0:
  t = Q.popleft()
  F[t] = 1
  for i in range(T):
    if Data[t][i] == 1:
      L[t][i] = 1
      if F[i] == 0:
        F[i] = 1
        Q.append(i)
for i in p:
  L[i][-1] = 1


while True:
  # s -> t ????????
  # ?????????
  P = DFS(L, 0, T - 1)
  if P == False:
    break
  # ?????????
  mi = 10 ** 20
  Last = T
  for i in range(1, Last):
    t = L[P[i - 1]][P[i]]
    if t < mi:
      mi = t
    if P[i] == T - 1:
      Last = i + 1
      break
  # ??????
  for i in range(1, Last):
    L[P[i - 1]][P[i]] -= mi
    L[P[i]][P[i - 1]] += mi

print(sum(L[-1]))