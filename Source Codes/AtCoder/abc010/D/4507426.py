class MFP:
  def __init__(self, num):
    self.Len = num
    self.L = [[0] * num for i in range(num)]

  def setL(self, a, b, x):
    self.L[a][b] = x

  def setS(self, s, X, Y):
    for i in range(len(X)):
      self.setL(s, X[i], Y[i])

  def setSn(self, s, X, n):
    Y = [n for i in range(len(X))]
    self.setS(s, X, Y)

  def setT(self, t, X, Y):
    for i in range(len(X)):
      self.setL(X[i], t, Y[i])

  def setTn(self, t, X, n):
    Y = [n for i in range(len(X))]
    self.setT(t, X, Y)

  def getAns(self, t):
    return sum(self.L[t])

  def DFS(self, s, t):
    S = [[s, 0]]
    P = [0] * self.Len
    D = [0] * self.Len
    while S != []:
      k = S.pop()
      P[k[1]] = k[0]
      if self.L[k[0]][self.Len - 1] > 0:
        P[k[1] + 1] = self.Len - 1
        return P
      for i in range(self.Len):
        if D[i] == 0 and self.L[k[0]][i] > 0:
          S.append([i, k[1] + 1])
          D[i] = 1
    return False

  def exe(self):
    while True:
      P = self.DFS(0, T - 1)
      if P == False:
        break
      mi = self.L[P[1]][P[0]]
      Last = self.Len
      for i in range(2, Last):
        if P[i - 1] == self.Len - 1:
          Last = i
          break
        t = self.L[P[i - 1]][P[i]]
        if t < mi:
          mi = t
      for i in range(1, Last):
        self.L[P[i - 1]][P[i]] -= mi
        self.L[P[i]][P[i - 1]] += mi

from collections import deque
N, G, E = list(map(int, input().split()))
p = list(map(int, input().split()))
ab = [list(map(int, input().split())) for i in range(E)]

T = N + 1
Data = [[0] * T for i in range(T)]

for i in ab:
  Data[i[0]][i[1]] = 1
  Data[i[1]][i[0]] = 1

Q = deque([0])
F = [0] * T

m = MFP(T)

# ????
while len(Q) > 0:
  t = Q.popleft()
  F[t] = 1
  for i in range(T):
    if Data[t][i] == 1:
      m.setL(t, i, 1)
      if F[i] == 0:
        F[i] = 1
        Q.append(i)

m.setTn(-1, p, 1)
m.exe()

print(m.getAns(-1))