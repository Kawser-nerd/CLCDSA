if __name__ == '__main__':
    T = int(raw_input())
    for caseno in xrange(T):
        n, k = [int(s) for s in raw_input().split()]
        if (k + 1) % (2 ** n) == 0:
            res = 'ON'
        else:
            res = 'OFF'
        print 'Case #%d: %s' % (caseno + 1, res)
