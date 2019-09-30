def solve(M, a, b, lev, missed):
    if a == b:
        return 0

    l = b - a
    pr = prices[lev - 1][a / 2 ** lev]

    cost1 = pr + solve(M, a, a + l / 2, lev - 1, missed) + solve(M, a + l / 2 + 1, b, lev - 1, missed)
    if all(m > missed for m in M[a:b + 1]):
        cost2 = solve(M, a, a + l / 2, lev - 1, missed + 1) + solve(M, a + l / 2 + 1, b, lev - 1, missed + 1)
        return min(cost1, cost2)
    else:
        return cost1

if __name__ == '__main__':
    for case in xrange(input()):
        P = int(raw_input())
        Ms = [int(s) for s in raw_input().split()]
        prices = []
        for _ in xrange(P):
            ll = [int(s) for s in raw_input().split()]
            prices += [ll]

        res = solve(Ms, 0, (2**P) - 1, P, 0)

        print 'Case #%d: %d' % (case+1, res)
