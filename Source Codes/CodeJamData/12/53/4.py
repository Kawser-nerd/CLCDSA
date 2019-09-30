import sys

if __name__ == "__main__":
    f = sys.stdin
    if len(sys.argv) >= 2:
        fn = sys.argv[1]
        if fn != '-':
            f = open(fn)

    t = int(f.readline())
    for _t in xrange(t):
        M, F, N = map(int, f.readline().split())
        foods = []

        for i in xrange(N):
            foods.append(map(int, f.readline().split()))
        foods.sort()

        best = 0
        for norders in xrange(1, M / F + 1):
            meals = 0
            money = M - norders * F
            for p, s in foods:
                if p > money:
                    break
                can_buy = min(norders * (s + 1) - meals, money / p)
                if can_buy >= 0:
                    meals += can_buy
                    money -= p * can_buy
            best = max(meals, best)
        print "Case #%d: %d" % (_t + 1, best)
