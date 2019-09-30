from operator import itemgetter
n = int(input())
info = [list(map(int,input().split())) for i in range(n)]

def solve(ans):
  x = [[info[i][0]-ans/info[i][2],info[i][0]+ans/info[i][2]] for i in range(n)]
  y = [[info[i][1]-ans/info[i][2],info[i][1]+ans/info[i][2]] for i in range(n)]

  #??????????
  x = sorted(x, key=itemgetter(1))
  y = sorted(y, key=itemgetter(1))  
  for i in range(n):
    if x[0][1] < x[i][0] :
      return False
    if y[0][1] < y[i][0] :
      return False
  return True

ok = 10000000000
ng = 0
while abs(ok-ng) > 10**(-6):
  mid = (ok+ng)/2
  if solve(mid):
    ok = mid
  else:
    ng = mid
print(mid)