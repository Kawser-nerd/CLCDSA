from itertools import product
h,w = map(int, input().split())
aft = [list(input()) for _ in range(h)]
bef = [["#"]*w for _ in range(h)]
d = (-1,0,1)
for y in range(h):
  for x in range(w):
    if aft[y][x] == ".":
      for dx,dy in product(d,repeat=2):
        nx = x + dx
        ny = y + dy
        if 0 <= nx < w and 0 <= ny < h:
          bef[ny][nx] = "."
aft2 = [["."]*w for _ in range(h)]
for y in range(h):
  for x in range(w):
    for dx,dy in product(d,repeat=2):
        nx = x + dx
        ny = y + dy
        if 0 <= nx < w and 0 <= ny < h and bef[ny][nx] == "#":
          aft2[y][x] = "#"
          break
if aft == aft2:
  print("possible")
  for i in range(h):
    print("".join(bef[i]))
else:
  print("impossible")