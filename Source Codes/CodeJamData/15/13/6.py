def read(parse):
  return [parse(_) for _ in raw_input().split()]

def cross(v1, v2):
  x1, y1 = v1
  x2, y2 = v2
  return x1 * y2 - x2 * y1

def clock(a, b):
  return cross(a, b) < 0

def solve():
  N = input()
  X, Y = zip(*[read(int) for i in range(N)])
  def vec(a, b):
    return (X[b] - X[a], Y[b] - Y[a])

  eps = 10**-5
  ans = [N - 1] * N
  for i in range(N):
    ar = [vec(i, j) for j in range(N)]
    upper = [j for j in range(N) if ar[j][1] > 0 or (ar[j][1] == 0 and ar[j][0] > 0)]
    lower = [j for j in range(N) if ar[j][1] < 0 or (ar[j][1] == 0 and ar[j][0] < 0)]
    upper.sort(cmp=lambda x, y: cross(ar[y], ar[x]))
    lower.sort(cmp=lambda x, y: cross(ar[y], ar[x]))
#    print i, upper, lower
#    print i, [ar[x] for x in upper], [ar[x] for x in lower]
    bad = len(lower)
    low = 0
    for up in upper:
      while low < len(lower) and not clock(ar[up], ar[lower[low]]):
        low += 1
        bad -= 1
      for x in [i, up]:
        ans[x] = min(ans[x], bad)
      bad += 1
    bad = len(upper)
    up = 0
    for low in lower:
      while up < len(upper) and not clock(ar[low], ar[upper[up]]):
        up += 1
        bad -= 1
      for x in [i, low]:
        ans[x] = min(ans[x], bad)
      bad += 1
    '''for j in range(N):
      if i == j:
        continue
      bad = sum(1 for k in range(N) if clock(vec(i, j), vec(i, k)))
      for x in [i, j]:
        ans[x] = min(ans[x], bad)'''
  return ans

T = input()
for t in range(1, T + 1):
  print 'Case #%d:' % t
  for x in solve():
    print x
