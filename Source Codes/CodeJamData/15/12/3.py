cases = int(raw_input())

def solve(t, times, B):
  a = 1
  c = 0
  for time in times:
    a += (t + time - 1) / time

    if (t % time == 0):
      c += 1

  b = a + max(c-1, 0)
  return a, b

for case in xrange(1, cases + 1):
  b, rank = [ int(t) for t in raw_input().split() ]
  times = [ int(t) for t in raw_input().split() ]

  #for i in xrange(0, 21):
  #  print i, solve(i, times, b)

  #break

  lo = 0
  hi = 10 ** 15

  ans = -1
  while lo <= hi:
    mid = (lo + hi) / 2
    lb, ub = solve(mid, times, b)

    if (rank < lb):
      hi = mid - 1
    elif rank > ub:
      lo = mid + 1
    else:
      ids = [ i + 1 for i in xrange(b) if mid % times[i] == 0 ]

      if (len(ids) == 0):
        lo = mid + 1
        continue

      assert 0 <= rank - lb < len(ids)

      ans = ids[rank - lb]
      break

  print "Case #%d: %d" % (case, ans)
