import collections
import sys

P = 1000000007

if __name__ == "__main__":
    f = sys.stdin
    if len(sys.argv) >= 2:
        fn = sys.argv[1]
        if fn != '-':
            f = open(fn)

    T = int(f.readline())
    for _T in xrange(T):
        M, N = map(int, f.readline().split())

        strings = []
        for i in xrange(M):
            strings.append(f.readline().strip())

        worst = 0
        nworst = 0
        for k in xrange(N ** M):
            servers = [[] for i in xrange(N)]
            for i in xrange(M):
                servers[k % N].append(strings[i])
                k /= N

            if any(not strset for strset in servers):
                continue

            total = 0
            # print
            # print servers
            for strset in servers:
                prefixes = set([""])
                for s in strset:
                    for i in xrange(len(s)):
                        prefixes.add(s[:i+1])
                # print strset, prefixes
                total += len(prefixes)

            if total > worst:
                worst = total
                nworst = 0
            if total == worst:
                nworst += 1

        print "Case #%d: %d %d" % (_T+1, worst, nworst % P)
