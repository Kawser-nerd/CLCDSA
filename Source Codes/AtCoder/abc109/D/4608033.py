h, w = map(int, input().split())
amap = [list(map(int, input().split())) for _ in range(h)]
n = 0
mv = []
for i, alist in enumerate(amap):
  for j in range(len(alist)):
    if i == len(amap) - 1 and j == len(alist) - 1:
      break
    if i % 2 == 0:
      if amap[i][j] % 2 == 1:
        amap[i][j] -= 1
        if j == len(alist) - 1:
          amap[i+1][j] += 1
          mv.append((i+1, j+1, i+2, j+1))
        else:
          amap[i][j+1] += 1
          mv.append((i+1, j+1, i+1, j+2))
        n += 1
    elif i % 2 == 1:
      if amap[i][-j-1] % 2 == 1:
        amap[i][-j-1] -= 1
        if j == len(alist) - 1:
          amap[i+1][0] += 1
          mv.append((i+1, 1, i+2, 1))
        else:
          amap[i][-j-2] += 1
          mv.append((i+1, len(alist)-j, i+1, len(alist)-j-1))
        n += 1
print(n)
for _mv in mv:
  print(*_mv)