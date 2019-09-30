N,D,K = map(int,input().split())
L = []
for i in range(D):
  L.append(list(map(int,input().split())))
M = []
for i in range(K):
  M.append(list(map(int,input().split())))
for i in range(K):
  cur = M[i][0]
  day = 0
  if M[i][0] < M[i][1]:
    for j in range(D):
      if L[j][0] <= cur <= L[j][1]:
        if L[j][0] <= M[i][1] <= L[j][1]:
          day += 1
          print(day)
          break
        else:
          day += 1
          cur = L[j][1]
      else:
        day += 1
  else:
    for j in range(D):
      if L[j][0] <= cur <= L[j][1]:
        if L[j][0] <= M[i][1] <= L[j][1]:
          day += 1
          print(day)
          break
        else:
          day += 1
          cur = L[j][0]
      else:
        day += 1