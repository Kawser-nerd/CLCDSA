def solve(gs, b):
    assert all(c == '1' for c in b)
    if b in gs:
        return 'IMPOSSIBLE'
    else:
        return "%s %s" % ('0?' * len(b), '1' * (len(b) - 1) if len(b) > 1 else '0')

if __name__ == '__main__':
    import sys
    fp = open(sys.argv[1])
    def readline():
        return fp.readline().strip()
    num_cases = int(readline())
    for i in xrange(num_cases):
        n, l = [int(x) for x in readline().split()]
        gs = readline().split()
        b = readline()
        print "Case #%d: %s" % (i + 1, solve(gs, b))
