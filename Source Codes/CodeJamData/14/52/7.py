import sys

if __name__ == "__main__":
    f = sys.stdin
    if len(sys.argv) >= 2:
        fn = sys.argv[1]
        if fn != '-':
            f = open(fn)

    T = int(f.readline())
    for _T in xrange(T):
        P, Q, N = map(int, f.readline().split())

        healths = []
        golds = []

        for i in xrange(N):
            h, g = map(int, f.readline().split())
            healths.append(h)
            golds.append(g)

        def num_hits_to_win(h):
            assert h > 0

            if P > Q:
                return 1

            t = 1
            while True:
                m = ((h - 1) % Q) + 1
                if 1 <= m <= P:
                    return t

                h -= P
                t += 1

        # for h in healths:
            # print h, num_hits_to_win(h)

        cur = {1: 0}

        for i in xrange(N):
            next = {}

            hits_needed = num_hits_to_win(healths[i])
            would_win = golds[i]

            # print
            # print "On creep %d" % i

            for shots, money in cur.iteritems():
                # print "Could have %d shots and %d gold" % (shots, money)
                do_nothing = (healths[i] + Q-1) / Q + shots

                # print "do nothing and would have %d shots" % do_nothing
                next[do_nothing] = max(next.get(do_nothing, 0), money)

                health = healths[i]
                if shots == 0:
                    health -= Q
                    shots += 1
                    if health <= 0:
                        continue

                # min_tower_shots = hits_needed - shots
                # if min_tower_shots * Q + (hits_needed - 1) * P > health:
                    # continue

                tower_shots = max((health - (hits_needed - 1) * P - 1) / Q, 0)
                next_shots = shots - hits_needed + tower_shots
                # print "tower shoots %d times, we shoot %d times; we'd have %d shots" % (tower_shots, hits_needed, next_shots)
                if next_shots < 0:
                    # print "we only have %d initial shots"
                    continue

                next[next_shots] = max(next.get(next_shots, 0), money + would_win)

            cur = next

        # print cur
        best = max(cur.itervalues())
        print "Case #%d: %d" % (_T+1, best)


