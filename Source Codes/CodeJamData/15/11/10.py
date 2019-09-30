import sys, itertools, collections
sys.setrecursionlimit(10000)

read_ints = lambda: map(int, raw_input().split())
read_int  = input

for no_t in xrange(1, read_int() + 1):
    n = read_int()
    a = read_ints()
    ans1 = sum(max(x - y, 0) for x, y in zip(a, a[1:]))

    mx = max(max(x - y, 0) for x, y in zip(a, a[1:]))
    ans2 = sum(min(x, mx) for x in a[:-1])
    print 'Case #%d: %s %s' % (no_t, ans1, ans2)
