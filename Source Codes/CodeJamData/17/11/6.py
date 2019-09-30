def process(x):
    first = None
    for c in x:
        if c != '?' and first is None:
            first = c
    if first is None:
        return None
    z = []
    last = first
    for c in x:
        if c == '?':
            z.append(last)
        else:
            z.append(c)
            last = c
    return ''.join(z)

tt = int(raw_input())
for t in xrange(1, tt+1):
    y = []
    n, m = map(int, raw_input().strip().split())
    for i in xrange(n):
        y.append(process(raw_input().strip()))
    u = []
    first = None
    for c in y:
        if c is not None and first is None:
            first = c
    z = []
    last = first
    print 'Case #%d:' % t
    for c in y:
        if c is None:
            print last
        else:
            print c
            last = c
