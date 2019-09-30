import sys

if __name__ == "__main__":
    f = sys.stdin
    if len(sys.argv) >= 2:
        fn = sys.argv[1]
        if fn != '-':
            f = open(fn)

    T = int(f.readline())
    for _T in xrange(T):
        s, K = f.readline().split()
        K = int(K)
        l = [c == '+' for c in s]

        flips = 0
        for i in xrange(len(s) - K + 1):
            if not l[i]:
                flips += 1
                for j in xrange(i, i + K):
                    l[j] = not l[j]

        if not all(l):
            ans = "IMPOSSIBLE"
        else:
            ans = flips


        print "Case #%d: %s" % (_T + 1, ans)
