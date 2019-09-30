import random

def calc(steps, r):
    return 2*r*steps + (4*steps - 2)*steps/2


def process():
    r, t = map(int, raw_input().split())
    st = 0
    end = 100000000000000000000
    while st < end:
        mid = (st+end+1)/2
        if calc(mid,r) <= t:
            st = mid
        else:
            end = mid-1
    print st

T = int(raw_input())
for t in xrange(T):
    print "Case #%d:" % (t+1),
    process()




