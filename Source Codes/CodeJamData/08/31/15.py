import math
for case in range(input()):
    P, K, L = map(int, raw_input().split(' '))
    V = sorted(map(int, raw_input().split(' ')), reverse=True)
    t = 0
    m = 1
    count = 0 
    for i in V:
        count += m * i
        t += 1
        if t == K:
            m += 1
            t = 0
    print 'Case #%s: %d' % (case + 1, count)
