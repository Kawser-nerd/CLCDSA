N, D, K = map(int, input().split())
X = list()
for i in range(D):
  X.append(list(int(x) for x in input().split()))
for j in range(K):
  x, y = map(int, input().split())
  if x < y:
    k = 0
    while True:
      if X[k][0] <= x <= X[k][1]:
        if y > X[k][1]:
          x = X[k][1]
        else:
          print(k+1)
          break
      k += 1
  else:
    k = 0
    while True:
      if X[k][0] <= x <= X[k][1]:
        if y < X[k][0]:
          x = X[k][0]
        else:
          print(k+1)
          break
      k += 1