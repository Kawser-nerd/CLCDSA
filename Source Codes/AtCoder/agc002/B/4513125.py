n,m = map(int, input().split())
xy = [list(map(int, input().split())) for i in range(m)]
red = [1]+[0]*(n-1)
ball = [1]*n
for i in xy:
  x,y = i[0]-1,i[1]-1
  if red[x] == 1:
    red[y] = 1
  ball[x] -= 1
  ball[y] += 1
  if ball[x] == 0:
    red[x] = 0
print(red.count(1))