import math

def Cover(C):
  if len(C) == 0:
    return 0.0
  if len(C) == 1:
    return C[0][2]
  return (C[0][2] + C[1][2] + math.sqrt((C[0][0] - C[1][0])**2 + (C[0][1] - C[1][1])**2))/2.0

for tc in range(1, int(input()) + 1):
  n = int(input())
  circles = []
  for i in range(n):
    x, y, r = map(int, input().split())
    circles.append((x, y, r))
  ans = None
  for i in range(n):
    nans = max(Cover(circles[i:i+1]), Cover(circles[0:i] + circles[i+1:n]))
    if ans is None or nans < ans:
      ans = nans
  print("Case #%d: %.6f" % (tc, ans))