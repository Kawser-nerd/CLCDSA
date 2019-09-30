import sys

if __name__ == "__main__":
    f = sys.stdin
    if len(sys.argv) >= 2:
        fn = sys.argv[1]
        if fn != '-':
            f = open(fn)

    t = int(f.readline())
    for _t in xrange(t):
        n = int(f.readline())
        stages = []
        for i in xrange(n):
            stages.append(map(int, sys.stdin.readline().split()))

        stars = 0
        progress = [0 for s in stages]
        games = 0

        bad = False
        while stars < 2 * n:
            found = False
            for i in xrange(n):
                if progress[i] < 2 and stages[i][1] <= stars:
                    games += 1
                    stars += 2 - progress[i]
                    progress[i] = 2
                    found = True
                    break

            if found:
                continue

            best = -1
            best_size = -1
            for i in xrange(n):
                if progress[i] == 0 and stages[i][0] <= stars:
                    if stages[i][1] > best_size:
                        best = i
                        best_size = stages[i][1]

            if best_size == -1:
                bad = True
                break
            assert best_size >= 0
            progress[best] = 1
            stars += 1
            games += 1

        if bad:
            print "Case #%d: Too Bad" % (_t + 1,)
        else:
            print "Case #%d: %d" % (_t + 1, games)
