import heapq

tt = int(raw_input())
for t in xrange(1, tt+1):
    r = []
    x = []
    packs = []
    ans = 0
    n, m = map(int, raw_input().strip().split())
    r = map(int, raw_input().strip().split())
    for i in xrange(n):
        qq = map(int, raw_input().strip().split())
        for q in qq:
            blo = (10*q+(11*r[i]-1))/(11*r[i])
            bhi = (10*q)/(9*r[i])
            if blo <= bhi:
                x.append((blo, bhi, i))
        h = []
        heapq.heapify(h)
        packs.append(h)
    x.sort()
    for (tlo, thi, item) in x:
        tnow = tlo
        heapq.heappush(packs[item], thi)
        foul = False
        for i in xrange(n):
            while len(packs[i]) > 0 and packs[i][0] < tnow:
                heapq.heappop(packs[i])
            if len(packs[i]) <= 0:
                foul = True
        if not foul:
            for i in xrange(n):
                heapq.heappop(packs[i])
            ans += 1
    print 'Case #%d: %d' % (t, ans)
