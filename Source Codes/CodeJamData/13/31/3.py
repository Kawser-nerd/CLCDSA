from sys import stdin
def solve():
    s, t = stdin.readline().split()
    t = int(t)
    p = -1
    a = 0
    cnt = 0
    for i, c in enumerate(s):
        if c not in 'aieuo':
            a = a + 1
            if a >= t:
                p = i + 1 - t
        else:
            a = 0
        cnt += p + 1
    return cnt
N = int(stdin.readline())
for i in xrange(N):
    print "Case #%d: %d" % (i+1, solve())
