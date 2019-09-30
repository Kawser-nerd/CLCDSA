n,m = map(int,input().split())
ball = [1]*(n+1)
red = [0]*(n+1)
red[1] = 1
for _ in range(m):
  x,y = map(int,input().split())
  ball[x] -= 1
  ball[y] += 1
  if red[x]:
    red[y] = 1
  if ball[x] == 0:
    red[x] = 0
print(sum(red))