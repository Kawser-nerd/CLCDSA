N = int(input())
 
intervals = tuple(tuple(map(int,input().split())) for _ in range(N))
 
L = sorted((l for l,r in intervals))
R = sorted((r for l,r in intervals), reverse=True)
 
def helper(L,R,turn):
  x = 0
  cost = 0
  T = [L,None,R]
  while True:
    y = T[turn+1].pop()
 
    if turn*(y-x) < 0:
      cost += abs(x-y)
      x = y
    else:
      break
    turn *= -1
  cost += abs(x)
  return cost

print(max(helper(L.copy(), R.copy(), t) for t in (-1,1)))