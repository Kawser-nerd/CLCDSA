# (10-x) ways: (0,x)-(9-x,9) -> (x, -x)           <- This should never happens when D > 0
# (x) ways:    (10-x,0)-(9,x-1) -> (x-10, 10 - x)

def solve(d, k, outer):
  if k <= 1:
    return 10**k if d == 0 else 0
  # if d >= 10**k:
  #   return 0

  t = (-d)%10 # 10-d%10 doesn't work when d = 10
  d -= t*10**(k-1) - t
  return (10-t-outer)*solve(abs(d//10), k-2, 0)

D = int(input())
result = 0
for k in range(1,20):
  result += solve(D, k, 1)

print(result)