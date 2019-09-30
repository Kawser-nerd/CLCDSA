from math import ceil, log
def solve(L,P,C):
    n = 0
    while L < P:
        L *= C
        n += 1
    return int(ceil(log(n, 2)))

if __name__ == '__main__':
    import sys
    rl = iter(sys.stdin).next
    for case in range(1, int(rl())+1):
        L,P,C = map(int, rl().split())
        print 'Case #%d: %s' % (case, solve(L,P,C))
