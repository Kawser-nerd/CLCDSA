tc = int(raw_input())

for t in range(1, tc+1):
    p = raw_input().split()
    n = int(p[0])
    p = map(int, p[1:])
    b = list(p)

    somma = sum(p)
    somma2 = sum(p)

    p = map(float, p)

    while somma > 0:
        m = min(p)
        c = p.count(m)
        d = min(somma, c)
        p = map(lambda a: a+float(d)/c if a == m else a, p)
        somma -= d

    res = []
    for i in range(n):
        res.append(float(p[i] - b[i]) / somma2 * 100)

    print "Case #%d: %s" % (t, ' '.join(map(str, res)))

            
            
