h, w, d = map(int, input().split())
amd = {}
for i in range(h):
  al = map(int, input().split())
  for j, a in enumerate(al):
    amd[a] = (j+1, i+1)

dsum = [0 for _ in range(d+1)]
for i in range(d+1, h*w+1):
  dsum.append(dsum[-d] + abs(amd[i][0]-amd[i-d][0]) + abs(amd[i][1]-amd[i-d][1]))

q = int(input())
for _ in range(q):
  ans = 0
  l, r = map(int, input().split())
  print(dsum[r] - dsum[l])