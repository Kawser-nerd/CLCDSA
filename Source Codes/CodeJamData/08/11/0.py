T = int(raw_input())
for X in range(1, T + 1):
    n = int(raw_input())
    v1 = sorted(map(lambda x: int(x), raw_input().split(' ')))
    v2 = sorted(map(lambda x: int(x), raw_input().split(' ')), reverse=True)
    Y = 0
    for i in range(n):
        Y += v1[i] * v2[i]
    print 'Case #%d:' % X, Y
