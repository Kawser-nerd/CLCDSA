
def Solution():
    D, I, M, N = map(int, raw_input().split())
    pix = map(int, raw_input().split())
    cost = [0] * 256
    for v in pix:
        cost1 = []
        for v1 in xrange(256):
            c1 = cost[v1] + D
            for v0 in xrange(256):
                c2 = cost[v0] + abs(v-v1)
                delta = abs(v1-v0)
                if delta > M:
                    if M:
                        c2 += ((delta-1)/M)*I
                    else:
                        c2 += 1000000000
                c1 = min(c2, c1)
            cost1.append(c1)
        cost = cost1
    print min(cost)

#---------------------------------------------------------------

T = int(raw_input())
for testcase in xrange(T):
    print "Case #%d:" % (testcase+1),
    Solution()
