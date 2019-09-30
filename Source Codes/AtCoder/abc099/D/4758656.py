n, c = map(int, input().split())

dmap = [list(map(int, input().split())) for _ in range(c)]
cmap = [list(map(int, input().split())) for _ in range(n)]

d1 = {}
d2 = {}
d3 = {}

for i, clist in enumerate(cmap):
  for j, _c in enumerate(clist):
    if (i + j + 2) % 3 == 2:
      if _c-1 in d1:
        d1[_c-1] += 1
      else:
        d1[_c-1] = 1
    elif (i + j + 2) % 3 == 0:
      if _c-1 in d2:
        d2[_c-1] += 1
      else:
        d2[_c-1] = 1
    else:
      if _c-1 in d3:
        d3[_c-1] += 1
      else:
        d3[_c-1] = 1

minc = None
for c1 in range(c):
  for c2 in range(c):
    for c3 in range(c):
      tmp = 0
      if c1 == c2 or c2 == c3 or c3 == c1:
        continue
      for _c, cn in d1.items():
        tmp += dmap[_c][c1] * cn
      for _c, cn in d2.items():
        tmp += dmap[_c][c2] * cn
      for _c, cn in d3.items():
        tmp += dmap[_c][c3] * cn
      if minc is None:
        minc = tmp
      elif minc > tmp:
        minc = tmp

print(minc)