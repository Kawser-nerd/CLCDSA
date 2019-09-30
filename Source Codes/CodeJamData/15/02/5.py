import sys

T = int(sys.stdin.readline())
for t in range(T):
    sys.stdin.readline()
    P = map(int, sys.stdin.readline().split())
    spl = [1]*len(P)
    res = 10000
    for i in range(1005):
        maxi = 0
        for j in range(len(P)):
            if (P[j] + spl[j] - 1) / spl[j] > (P[maxi] + spl[maxi] - 1) / spl[maxi]:
                maxi = j
        res = min(res, i + (P[maxi] + spl[maxi] - 1) / spl[maxi])
        spl[maxi] += 1
    print "Case #%d: %d" % (t+1, res)
