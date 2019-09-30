ax, ay, bx, by = map(int, input().split())
n = int(input())
xy = [list(map(int, input().split())) for _ in range(n)]
def check(x, y, z, w):
  s = (bx-ax)*(y-ay) - (by-ay)*(x-ax)
  t = (bx-ax)*(w-ay) - (by-ay)*(z-ax)
  u = (z-x)*(ay-y) - (w-y)*(ax-x)
  v = (z-x)*(by-y) - (w-y)*(bx-x)
  return s * t < 0 and u * v < 0
cnt = 0
for i in range(n):
  if check(xy[i][0], xy[i][1], xy[(i+1)%n][0], xy[(i+1)%n][1]):
    cnt += 1
print(1 + cnt//2)