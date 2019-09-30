def flip(c):
    if c == '0':
        return '1'
    else:
        return '0'

T = int(raw_input())

for z in xrange(1,T+1):
    N, L = map(int,raw_input().split())

    flow = raw_input().split()
    devices = raw_input().split()

    sd = set(devices)

    best = 1000000

    for i in xrange(N):
        num_flips = 0
        flipped = [False for j in xrange(L)]
        for j in xrange(L):
            if flow[0][j] != devices[i][j]:
                num_flips += 1
                flipped[j] = True

        real_flow = []
        for f in flow:
            s = ''
            for j in xrange(L):
                cur = f[j]
                if flipped[j]:
                    cur = flip(cur)
                s += cur
            real_flow.append(s)

        rf = set(real_flow)
        if rf == sd:
            best = min(best, num_flips)

    if best <= L:
        print "Case #%d: %d" % (z, best)
    else:
        print "Case #%d: NOT POSSIBLE" % (z)
