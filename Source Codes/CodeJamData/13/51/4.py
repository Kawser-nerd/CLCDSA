import sys

if __name__ == "__main__":
    f = sys.stdin
    if len(sys.argv) >= 2:
        fn = sys.argv[1]
        if fn != '-':
            f = open(fn)

    T = int(f.readline())
    for _T in xrange(T):
        B, N = map(int, f.readline().split())
        _bets = map(int, f.readline().split())
        assert len(_bets) == N

        while len(_bets) < 37:
            _bets.append(0)
        _bets.sort()
        # print _bets

        best = 0.0
        total_bet = 0

        for num_min in xrange(1, 37):
            bets = list(_bets)

            def cost(size):
                t = 0
                for i in xrange(num_min):
                    assert size >= bets[i]
                    t += size - bets[i]
                for i in xrange(num_min, 37):
                    if bets[i] <= size:
                        t += (size+1) - bets[i]
                return t

            low = max(bets[:num_min])-1
            high = 10000000000000
            while high > low:
                g = (high + low + 1) / 2
                c = cost(g)
                # print num_min, g, c
                if c > B:
                    high = g - 1
                else:
                    low = g
                    amount_bet = g * num_min - sum(bets[:num_min])
                    best = max(amount_bet * 36.0 / num_min - c, best)
        print "Case #%d: %.9f" % (_T+1, best)
