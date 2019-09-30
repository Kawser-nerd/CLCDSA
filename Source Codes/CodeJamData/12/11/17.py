def ints():
    return map(int, raw_input().split())

num_cases, = ints()

for case_num in xrange(1, num_cases + 1):
    A, B = ints()
    p = map(float, raw_input().split())
    best = 1 + B
    q = 1.0
    for a in xrange(1, A+1):
        # keep first a chars
        q *= p[a-1]
        option = A + B - 2*a + (1-q) * (B+1)
        best = min(best, option)
    print "Case #%d: %f" % (case_num, 1 + best)
