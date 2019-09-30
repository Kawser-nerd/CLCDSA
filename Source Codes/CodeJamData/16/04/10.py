tnum = int(raw_input())
for tcou in range(tnum):
    k, c, s = [int(x) for x in raw_input().split()]
    print "Case #{}:".format(tcou+1),
    if s*c<k:
        print "IMPOSSIBLE"
    else:
        for i in range((k+c-1)/c):
            m = 0
            for j in range(i*c, min((i+1)*c, k)):
                m = m*k+j
            print m+1,
        print
