import itertools

test_count = raw_input()
r, n, m, k = map(int, raw_input().split())
print "Case #1:"
for _ in xrange(r):
    products = map(int, raw_input().split())
    for sequence in itertools.combinations_with_replacement(xrange(2, m + 1), n):
        ps = set([])
        for mask in xrange(1 << n):
            p = 1
            for i in xrange(n):
                if mask >> i & 1:
                    p *= sequence[i]
            ps.add(p)
        valid = True
        for p in products:
            valid &= p in ps
        if valid:
            print ''.join(map(str, sequence))
            break
