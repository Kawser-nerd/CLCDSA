if __name__ == '__main__':
    T = int(raw_input())
    for caseno in xrange(T):
        R, k, N = [int(s) for s in raw_input().split()]
        g = [int(s) for s in raw_input().split()]

        h = []
        cycle = {}
        used_cycle = False
        pos = 0
        profit = 0
        while R:
            if not used_cycle and pos in cycle:
                cycle_len = len(h) - cycle[pos]
                cycle_profit = sum(c for _, c in h[cycle[pos]:])

                cnt = R // cycle_len
                R -= cnt * cycle_len
                profit += cnt * cycle_profit

                used_cycle = True

            if R == 0:
                break

            npos = pos
            curr = 0
            gcnt = 0
            while curr + g[npos] <= k and gcnt < N:
                curr += g[npos]
                npos = (npos + 1) % N
                gcnt += 1

            profit += curr
            cycle[pos] = len(h)
            h += [(pos, curr)]
            pos = npos
            R -= 1

        print 'Case #%d: %d' % (caseno + 1, profit)
