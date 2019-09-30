import sys

tn = int(sys.stdin.readline())

for ti in xrange(tn):
    n = int(sys.stdin.readline())
    match = {}
    edges = {}
    bside = set()
    for i in xrange(n):
        a, b = sys.stdin.readline().strip().split()
        bside.add(b)
        if a not in edges:
            edges[a] = []
        edges[a].append(b)
    def dfs(a):
        for b in edges[a]:
            if b not in was:
                was.add(b)
                if b not in match or dfs(match[b]):
                    match[b] = a
                    return True
        return False
    m = 0
    for a in edges:
        was = set()
        m += dfs(a)
    mc = len(edges)+len(bside)-m
    ret = n-mc
    #print m, mc, ret
    print 'Case #{0}: {1}'.format(ti+1, n-mc)
