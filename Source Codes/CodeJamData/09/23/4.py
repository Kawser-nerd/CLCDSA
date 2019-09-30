import sys
import psyco
psyco.full()
di = (-1, +1, 0, 0)
dj = (0, 0, -1, +1)
A, W = None, None
cache = None

def cached(f):
  def wrapper(*args, **kwargs):
    global cache
    key = str((f.__name__, args, kwargs))
    if key not in cache:
      cache[key] = f(*args, **kwargs)
    return cache[key]
  return wrapper

def move(i, j, d):
  ii, jj = i+di[d], j+dj[d]
  if ii < 0 or jj < 0 or ii >= W or jj >= W:
    return None
  return ii, jj

@cached
def solve(i, j, minus, sum, len):
  value = int(A[i][j])
  if minus: value *= -1

  if len == 1:
    if value == sum:
      return ('-' if minus else '+') + str(abs(value))
    return None

  best = None
  for x in range(4):
    sign = move(i, j, x)
    if not sign:
      continue
    i1, j1 = sign
    for y in range(4):
      next = move(i1, j1, y)
      if not next:
        continue
      i2, j2 = next
      link = solve(i2, j2, A[i1][j1] == '-', sum-value, len-1)
      if link and (best is None or best > link):
        best = link
  if best is None:
    return None
  return ('-' if minus else '+') + str(abs(value)) + best


def main():
  global A, W, cache

  T = int(raw_input())
  for t in range(1, T+1):
    print 'Case #%d:' % t
    W, Q = map(int, raw_input().split())
    A = []
    for i in range(W):
      A.append(raw_input())
    queries = map(int, raw_input().split())
    assert len(queries) == Q
    print >>sys.stderr, 'Test #%d: %d size %d queries...' % (t, W, Q),

    cache = {}
    for q in queries:
      length = 1
      solution = None
      while True:
        for i in range(W):
          for j in range(W):
            if A[i][j] in ('+', '-'):
              continue
            test = solve(i, j, False, q, length)
            if test and (solution is None or solution > test):
              solution = test
        if solution:
          break
        length += 1
      print solution[1:]
    print >>sys.stderr, 'done'

if __name__ == '__main__':
  sys.setrecursionlimit(100000)
  main()
