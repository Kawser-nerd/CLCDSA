def diamond(i, parents):
    ancestors = set()
    q = [i]
    while q:
        i = q.pop()
        if i in ancestors:
            return True
        ancestors.add(i)
        q += parents[i]
    return False

T = int(raw_input())
for case in xrange(1, T+1):
    N = int(raw_input())
    parents = [map(lambda x: int(x)-1, raw_input().split()[1:]) for i in xrange(N)]
    print 'Case #%i:' % case,
    if any(diamond(i, parents) for i in xrange(N)):
        print 'Yes'
    else:
        print 'No'
