x,y = map(int,input().split())
ans = 0
while True:
  if x == y:
    print(ans)
    break
  
  if x == -y:
    x = -x
    ans += 1
    continue

  if (abs(x)<abs(y) and x<0) or (abs(y)<abs(x) and 0<=x):
    x = -x
    ans += 1
    continue
  
  ans += abs(abs(x)-abs(y))
  x += abs(abs(x)-abs(y))