import sys

P = 1000002013

if __name__ == "__main__":
    f = sys.stdin
    if len(sys.argv) >= 2:
        fn = sys.argv[1]
        if fn != '-':
            f = open(fn)

    T = int(f.readline())
    for _T in xrange(T):
        N, M = map(int, f.readline().split())
        peep = []
        stops = set()
        for i in xrange(M):
            peep.append(map(int, f.readline().split()))
            stops.add(peep[-1][0])
            stops.add(peep[-1][1])
        assert all(len(p) == 3 for p in peep)
        stops = list(stops)
        stops.sort()
        # print peep, stops

        loss = 0
        total_loss = 0
        tickets = {}

        def grab(p, l):
            t = 0
            for k, v in sorted(tickets.items()):
                x = min(v, p)
                t += (l - k) * x
                p -= x
                tickets[k] -= x
                if not tickets[k]:
                    del tickets[k]
                if not p:
                    break
            return t

        prev = 0
        for s in stops:
            # print "Loss from %d to %d: %d per, %d total" % (prev, s, loss, (s - prev) * loss)
            total_loss += (s - prev) * loss
            tickets = dict((k + (s - prev), v) for (k, v) in tickets.iteritems())
            for o, e, p in peep:
                if s == o:
                    tickets[0] = tickets.get(0, 0) + p
            for o, e, p in peep:
                if s == e:
                    loss += grab(p, (e - o))
            prev = s

        print "Case #%d: %d" % (_T+1, total_loss % P)
