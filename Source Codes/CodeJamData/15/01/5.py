import sys

T = int(sys.stdin.readline())
for t in range(T):
    _, d = sys.stdin.readline().split()
    c = 0
    res = 0
    for i in range(len(d)):
        res = max(res, i - c)
        c += int(d[i])
    print "Case #%d: %d" % (t+1, res)
