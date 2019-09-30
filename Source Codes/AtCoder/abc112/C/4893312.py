N = int(input())
xyh = [list(map(int, input().split())) for i in range(N)]
maxh = 0
minh = 10 ** 9
for i in range(N):
  if xyh[i][2] > maxh:
    maxh = xyh[i][2]
  if xyh[i][2] < minh:
    minh = xyh[i][2]
def hantei(x, y, h):
  for i in range(N):
    if max(h - abs(xyh[i][0] - x) - abs(xyh[i][1] - y), 0) != xyh[i][2]:
      return(False)
  return(True)

def solve():
  for p in range(maxh, minh + 205):
    for q in range(101):
      for r in range(101):
        if hantei(q,r,p) == True:
          return([q,r,p])
print(solve()[0],solve()[1],solve()[2])