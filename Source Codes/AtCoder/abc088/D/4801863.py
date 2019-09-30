from queue import Queue

H, W =  list(map(int, input().split()))
s = [input() for _ in range(H)]
 
y = "."
n = "#"

D = [[0] * W for _ in range(H)]
num = 0
for i in range(H):
  for j in range(W):
    if s[i][j] == y:
      num += 1
    else:
      D[i][j] = -1

def setWall(D, x):
  H = len(D)
  W = len(D[0]) + 2
  D = [[x] * W] + [[x] + [i for i in j] + [x] for j in D] + [[x] * W] 
  return D

D = setWall(D, -1)

D[1][1] = 1
Q = Queue()
Q.put([1, 1])
while Q.empty() != True:
  x, y = Q.get()
  t = D[x][y]
  for i in (-1, 1):
    for j in (0, 1):
      a = j * i
      b = (1 - j) * i
      if D[x + a][y + b] > t + 1 or D[x + a][y + b] == 0:
        D[x + a][y + b] = t + 1
        Q.put([x + a, y + b])

if D[H][W] == 0:
  print(-1)
else:
  print(num - D[H][W])