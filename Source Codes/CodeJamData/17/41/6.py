import sys
import numpy as np

if __name__ == "__main__":
    f = sys.stdin
    if len(sys.argv) >= 2:
        fn = sys.argv[1]
        if fn != '-':
            f = open(fn)

    T = int(f.readline())
    for _T in xrange(T):
        N, P = map(int, f.readline().split())
        G = map(int, f.readline().split())

        dp = np.zeros((102, 102, 102), dtype=np.int32)
        counts = np.zeros(4, dtype=np.int32)
        for g in G:
            counts[g % P] += 1
        dp[tuple(counts[1:])] = counts[0]
        # print tuple(counts[1:]), counts[0]

        newcounts = np.zeros(4, dtype=np.int32)
        for newcounts[1] in xrange(counts[1], -1, -1):
            for newcounts[2] in xrange(counts[2], -1, -1):
                for newcounts[3] in xrange(counts[3], -1, -1):
                    if (newcounts[1:] == counts[1:]).all():
                        continue

                    mod = ((counts - newcounts) * np.arange(4)).sum()
                    idx = tuple(newcounts[1:])

                    if (mod - 1) % P == 0:
                        dp[idx] = max(dp[idx], dp[newcounts[1] + 1, newcounts[2], newcounts[3]] + 1)
                    else:
                        dp[idx] = max(dp[idx], dp[newcounts[1] + 1, newcounts[2], newcounts[3]])
                    if (mod - 2) % P == 0:
                        dp[idx] = max(dp[idx], dp[newcounts[1], newcounts[2] + 1, newcounts[3]] + 1)
                    else:
                        dp[idx] = max(dp[idx], dp[newcounts[1], newcounts[2] + 1, newcounts[3]])
                    if (mod - 3) % P == 0:
                        dp[idx] = max(dp[idx], dp[newcounts[1], newcounts[2], newcounts[3] + 1] + 1)
                    else:
                        dp[idx] = max(dp[idx], dp[newcounts[1], newcounts[2], newcounts[3] + 1])

                    # print newcounts, mod, dp[idx]

        print "Case #%d: %d" % (_T + 1, dp[0,0,0])
