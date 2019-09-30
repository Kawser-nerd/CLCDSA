T = int(raw_input())
for tt in xrange(T):
    N, J = map(int, raw_input().strip().split());
    print "Case #" + str(tt + 1) + ":"
    f = 2 ** (N // 2) + 1
    base = 2 ** (N // 2 - 1) + 1
    gg = ""
    for i in range(2, 11):
        gg += " " + str(i ** (N // 2) + 1)
    for i in xrange(J):
        print bin((base + i * 2) * f)[2:] + gg

