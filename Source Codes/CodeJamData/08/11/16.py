filename = "A-large.in"
f = open(filename, 'r')
of = open("A-large.out", 'w')

N = int(f.readline())

for x in xrange(N):
    n = int(f.readline())
    a = f.readline().split(' ')
    b = f.readline().split(' ')
    a = [int(y) for y in a]
    b = [int(y) for y in b]
    a.sort()
    b.sort(reverse=True)
    s = 0
    for y in xrange(len(a)):
        s += a[y]*b[y]
    print >> of, "Case #%d: %d" % (x + 1, s)


f.close()
of.close()
