i = open('1a.in', 'r')

test_cases = int(i.readline())

for t in range(1, test_cases+1):
    v = int(i.readline())
    va = [int(z) for z in i.readline().split()]
    vb = [int(z) for z in i.readline().split()]
    va.sort()
    vb.sort(reverse=True)
    r = 0
    for p in range(len(va)):
        r += va[p] * vb[p]

    print "Case #%d: %d" % (t, r)
