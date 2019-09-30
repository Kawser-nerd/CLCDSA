r,b = map(int,input().split())
x,y = map(int,input().split())

def solve(ans):
  tmp_r = r - ans
  tmp_b = b - ans
  tmp_x = x - 1
  tmp_y = y - 1
  
  if tmp_r < 0 and tmp_b < 0:
    return False
  cnt = tmp_r//tmp_x + tmp_b//tmp_y
  
  if cnt >= ans :
    return True
  else:
    return False

ok = 0
ng = min(r,b)+1
while abs(ok-ng) > 1:
  mid = (ok+ng)//2
  if solve(mid):
    ok = mid
  else:
    ng = mid

print(ok)