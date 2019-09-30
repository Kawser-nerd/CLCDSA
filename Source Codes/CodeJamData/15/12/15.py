def read(parse):
  return [parse(_) for _ in raw_input().split()]

def solve():
  B, N = read(int)
  ar = read(int)
  if N <= B:
    return N

  def count(t): # guys done at time t
    return sum(t / x for x in ar)
  lo = 0
  hi = N * min(ar)
  while lo < hi:
    mid = (lo + hi) / 2
    if count(mid) >= N - B:
      hi = mid
    else:
      lo = mid + 1
#  print lo, count(lo - 1)
  place = (N - B) - count(lo - 1)
#  print place
  lst = [x for x in range(B) if lo % ar[x] == 0]
  return lst[place - 1] + 1

T = input()
for t in range(1, T + 1):
  print 'Case #%d: %d' % (t, solve())
