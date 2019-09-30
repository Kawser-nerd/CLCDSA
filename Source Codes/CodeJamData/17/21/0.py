from sys import stdin

for cn in xrange(1,1+int(stdin.readline())):
    (D,N) = tuple(int(z) for z in stdin.readline().split())
    slowest = 0
    for h in xrange(N):
        (K,S) = tuple(int(z) for z in stdin.readline().split())
        time = float(D-K)/S
        slowest = max(slowest, time) # max not min
    speed = D / slowest
    print "Case #{}: {}".format(cn, speed)
