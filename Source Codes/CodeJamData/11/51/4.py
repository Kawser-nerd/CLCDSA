def ints():
  return map(int, raw_input().split())

def floats():
  return map(float, raw_input().split())

num_cases, = ints()

def find_at(P, x):
  if x == 0:
    return P[0][1]
  i = 0
  while P[i][0] < x:
    i += 1
  x1, y1 = P[i-1]
  x2, y2 = P[i]
  m = (y2 - y1) / (x2 - x1)
  return y1 + m * (x - x1)

for case_num in xrange(1, num_cases + 1):
  W, L, U, G = ints()
  lower = []
  upper = []
  for i in xrange(L):
    lower.append(floats())
  for i in xrange(U):
    upper.append(floats())
  points = []
  xs = set()
  for p in lower:
    xs.add(p[0])
  for p in upper:
    xs.add(p[0])
  xs = list(xs)
  xs.sort()
  for x in xs:
    points.append((x, find_at(upper, x) - find_at(lower, x)))
  A = [0]
  for i in xrange(len(points) - 1):
    x1, y1 = points[i]
    x2, y2 = points[i+1]
    h = (y1 + y2) / 2.0
    a = h * (x2 - x1)
    aa = A[-1]
    A.append(a + aa)
  res = []
  for frac in xrange(1, G):
    target = A[-1] * frac / G
    i = 0
    while A[i] < target:
      i += 1
    i -= 1
    a = target - A[i]
    x1, y1 = points[i]
    x2, y2 = points[i+1]
    h = y1
    m = (y2 - y1) / (x2 - x1)
    if abs(m) < 0.0001:
      x = a / h
    else:
      delta = h*h + 2 * m * a
      sign = 1
      x = (-h + sign * (delta ** 0.5)) / m
    res.append(x1 + x)

  print "Case #%d:\n%s" % (case_num, '\n'.join(map(str, res)))
