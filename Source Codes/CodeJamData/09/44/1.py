import sys

EPS = 1e-7

def works(X, Y, R, radius):
  N = len(X)
  for i in range(N):
    for j in range(i+1, N):
      d = (X[i]-X[j])**2 + (Y[i]-Y[j])**2
      r = (2*radius - R[i] - R[j])**2
      if d < r + EPS:
        return True
  return False

def main():
  T = int(raw_input())
  for t in range(1, T+1):
    print 'Case #%d:' % t,
    N = int(raw_input())
    X, Y, R = [], [], []
    for i in range(N):
      x, y, r = map(int, raw_input().split())
      X.append(x)
      Y.append(y)
      R.append(r)

    if N > 3:
      print >>sys.stderr, N
      print '?'
      continue

    if N < 3:
      print '%.6f' % max(R)
      continue

    left = max(R)
    right = 10000.0
    for iteration in range(1000):
      mid = (left + right) * 0.5
      if works(X, Y, R, mid):
        right = mid
      else:
        left = mid

    print '%.6f' % left

if __name__ == '__main__':
  main()
