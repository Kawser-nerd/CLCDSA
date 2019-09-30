n = int(input())
info = [list(map(int,input().split())) for i in range(n)]

max_time = 0
for i in range(n):
  max_time = max(max_time, info[i][0]+info[i][1]*(n-1))
  
def solve(mid):
  time = [0]*n
  for i in range(n):
    time[i] = (mid-info[i][0])/info[i][1]
  time = sorted(time)
#  print(time)
  for i in range(n):
    if time[i] < i:
      return False
  else:
    return True

ng = 0
ok = max_time+1

while abs(ok-ng) > 1:
  mid = (ok+ng)//2
  if solve(mid):
    ok = mid
  else:
    ng = mid
 # print(ok,mid,ng)
print(ok)