rl = raw_input
T = int(rl())

def count_served_by(time):
    if time < 0: return 0
    served_cnt = 0
    for m in M:
        served_cnt += (time + m) / m
    return served_cnt


for c in xrange(T):
    B, N = map(int, rl().strip().split())
    M = map(int, rl().strip().split())

    cant_be_served = -1
    will_be_served = 100000 * N + 1

    while cant_be_served + 1 < will_be_served:

        cand = (cant_be_served + will_be_served) / 2

        if count_served_by(cand) >= N:
            will_be_served = cand
        else:
            cant_be_served = cand

    # print 'will be served at time %d' % will_be_served

    remaining = N - count_served_by(will_be_served - 1)
    # print 'remaining %d' % remaining
    for i, m in enumerate(M):
        if will_be_served % m == 0:
            if remaining == 1:
                print 'Case #%d: %d' % (c+1, i+1)
                break
            else:
                remaining -= 1
    
