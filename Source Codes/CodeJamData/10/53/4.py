from collections import defaultdict

if __name__ == '__main__':
    for case in xrange(input()):

        cnt = defaultdict(int)

        C = int(raw_input())
        for _ in xrange(C):
            p, v = [int(s) for s in raw_input().split()]
            cnt[p] = v

        res = 0
        while True:
            found = None
            for p in cnt:
                if cnt[p] > 1:
                    found = p
                    break

            if found is None:
                break

            cnt[p] -= 2
            if cnt[p] == 0:
                del cnt[p]
            cnt[p - 1] += 1
            cnt[p + 1] += 1

            res += 1

        print 'Case #%d: %d' % (case+1, res)
