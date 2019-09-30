h, w, d = [int(item) for item in input().split()]
a = [[int(item) for item in input().split()] for _ in range(h)]
q = int(input())
lr = [[int(item) for item in input().split()] for _ in range(q)]

size = h * w
dist = [[0] * ((size)//d + 1) for _ in range(d)]
ilist = [0] * (size+1)
jlist = [0] * (size+1)

for i in range(h):
  for j in range(w):
    ilist[a[i][j]] = i
    jlist[a[i][j]] = j

def get_dist(x, y):
  distance = abs(ilist[x] - ilist[y]) + abs(jlist[x] - jlist[y])
  return distance

for i in range(d):
  for j in range((size)//d + 1):
    if (j-1)*d+i <= 0 or j*d + i > size:
      continue
    dist[i][j] = dist[i][j-1] + get_dist(j*d+i, (j-1)*d+i)

for l, r in lr:
  print(dist[r%d][r//d] - dist[l%d][l//d])