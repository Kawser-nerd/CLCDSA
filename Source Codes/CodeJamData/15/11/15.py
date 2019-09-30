def solve():
  N = input()
  ar = [int(_) for _ in raw_input().split()]
  diffs = [a - b for a, b in zip(ar, ar[1:])]
  eat1 = sum(max(x, 0) for x in diffs)
  rate = max(diffs + [0])
  eat2 = sum(min(x, rate) for x in ar[:-1])
  return eat1, eat2


T = input()
for t in range(1, T + 1):
  a, b = solve()
  print 'Case #%d: %d %d' % (t, a, b)
