import sys

T = int(raw_input())

def components(path):
    parts = path.split('/')[1:]
    for i in xrange(len(parts)):
        yield '/'.join(parts[:i+1])

for testCase in xrange(1, T+1):
    N, M = raw_input().split()
    N, M = int(N), int(M)
    tree = set()
    for i in xrange(N):
        dir = raw_input()
        for p in components(dir):
            tree.add(p)
    added = 0
    for j in xrange(M):
        dir = raw_input()
        for p in components(dir):
            if p not in tree: 
                added += 1
            tree.add(p)
    print "Case #%d: %d" % (testCase, added)

