def ints():
  return map(int, raw_input().split())

num_cases, = ints()

for case_num in xrange(1, num_cases + 1):
  N, = ints()
  vals = ints()
  num_sorted = sum(1 for i in xrange(N) if vals[i] == i+1)

  print "Case #%d: %f" % (case_num, N - num_sorted)
