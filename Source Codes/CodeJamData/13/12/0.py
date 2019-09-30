import sys

if __name__ == "__main__":
    f = sys.stdin
    if len(sys.argv) >= 2:
        fn = sys.argv[1]
        if fn != '-':
            f = open(fn)

    T = int(f.readline())
    for _T in xrange(T):
        E, R, N = map(int, f.readline().split())
        days = map(int, f.readline().split())

        if R > E:
            R = E

        total = 0
        first = 0
        energy_at = [E]
        for cur in xrange(N):
            amount = R if (cur != N-1) else E

            # print "end of day", cur
            while amount:
                best_idx = -1
                best = 0
                for i in xrange(first, cur+1):
                    assert energy_at[i]
                    if energy_at[i] and days[i] > best:
                        best_idx = i
                        best = days[i]
                assert best
                used = min(energy_at[best_idx], amount)
                # print "spending %d on day %d" % (used, best_idx)
                assert used > 0

                for i in xrange(best_idx, cur+1):
                    energy_at[i] -= used
                    if energy_at[i] == 0:
                        first = i+1
                amount -= used
                total += best * used
            energy_at.append(E)
        print "Case #%d: %d" % (_T+1, total)
