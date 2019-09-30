h,w = map(int, input().split())
S = [input() for i in range(h)]

def count(x,y):
  p = 0
  if x >= 1 and y >= 1 and S[x-1][y-1] == "#":
    p += 1
  if x >= 1 and S[x-1][y] == "#":
    p += 1
  if x >= 1 and y <= w - 2 and S[x-1][y+1] == "#":
    p += 1
  if y >= 1 and S[x][y-1] == "#":
    p += 1
  if y <= w - 2 and S[x][y+1] == "#":
    p += 1
  if x <= h - 2 and y >= 1 and S[x+1][y-1] == "#":
    p += 1
  if x <= h - 2 and S[x+1][y] == "#":
    p += 1
  if x <= h - 2 and y <= w - 2 and S[x+1][y+1] == "#":
    p += 1
  p = str(p)
  return(p)

for i in range(h):
  ans = ""
  for j in range(w):
    if S[i][j] == "#":
      ans += "#"
    else:
      ans += count(i,j)
  print(ans)