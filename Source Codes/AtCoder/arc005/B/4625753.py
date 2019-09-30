x, y, w = input().split()
x, y = int(x)-1,int(y)-1
dire = ["R", "L", "U", "D", "RU", "RD", "LU", "LD"]
dxy = [(1,0),(-1,0),(0,-1),(0,1),(1,-1),(1,1),(-1,-1),(-1,1)]
d = dict(zip(dire,dxy))
dx, dy = d[w]
s = ""
c = [input() for _ in range(9)]
for _ in range(4):
  s += c[y][x]
  x += dx
  y += dy
  if x == 9:
    x = 7
    dx *= -1
  elif x == -1:
    x = 1
    dx *= -1
  if y == 9:
    y = 7
    dy *= -1
  elif y == -1:
    y = 1
    dy *= -1
print(s)