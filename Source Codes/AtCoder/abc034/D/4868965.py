n,k = map(int,input().split())
info = [[0]+list(map(int,input().split())) for i in range(n)]

#?????
def solve(ans):
  global info
  
  for i in range(n):
    info[i][0] = info[i][1]*info[i][2] - ans*info[i][1]
  info = sorted(info,reverse = True)

  parameter = 0
  for i in range(k):
    parameter +=  info[i][0]

  if parameter >= 0:
    return True
  else:
    return False


ok = 0
ng = 100

while abs(ok-ng)>=10**(-6):
  mid = (ok+ng)/2
  if solve(mid):
    ok = mid
  else:
    ng = mid
    
print(mid)