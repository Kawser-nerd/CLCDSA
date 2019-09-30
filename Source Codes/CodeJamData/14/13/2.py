criteria = 485000

def chara(a):
    return sum([(a[i] - i) % len(a) for i in xrange(len(a))])

def solve(a):
    return 'GOOD' if chara(a) >= criteria else 'BAD'

T = input()
for i in xrange(T):
    n = input()
    a = map(int, raw_input().split())
    print 'Case #%d: %s' % (i + 1, solve(a))
