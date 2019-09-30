from collections import defaultdict

MOD = 1000000007

def factorial(n):
    ret = 1
    for i in xrange(2,n+1):
        ret *= i
        ret %= MOD
    return ret

def to_index(ch):
    return ord(ch) - ord('a')

def solve(trains):
    middle = set()
    has = set()
    homo_count = defaultdict(lambda: 0)
    adj = [[0] * 26 for i in xrange(26)]

    for t in trains:
        for c in t:
            has.add(to_index(c))
        for i in xrange(len(t)):
            if t[i] not in (t[0], t[-1]):
                middle.add(to_index(t[i]))
        if len(set(t)) == 1:
            homo_count[to_index(t[0])] += 1

        for i in xrange(0, len(t)-1):
            if t[i] != t[i+1]:
                a = to_index(t[i])
                b = to_index(t[i+1])
                adj[a][b] += 1
                adj[b][a] += 1

    # sanity checks: 

    # 0. everything that appears in the middle cannot have homogeneous string
    for mid in middle:
        if homo_count[mid] > 0:
            return 0
        
    # 1. all degree are up to 2
    degree = [sum(adj[i]) for i in xrange(26)]
    if max(degree) > 2: return 0

    # 2. no pair of vertices have duplicate edges
    for i in xrange(26):
        for j in xrange(26):
            if adj[i][j] > 1: 
                return 0

    def dfs(here, component):
        if seen[here]: return
        seen[here] = True
        component.append(here)
        for there in range(26):
            if adj[here][there]:
                dfs(there, component)

    def solveFor(component):
        degree_cnt = [0] * 3
        for c in component:
            degree_cnt[degree[c]] += 1

        # no cycles: everything must be a chain
        if len(component) > 1:
            if degree_cnt[1] != 2 or degree_cnt[2] != len(component)-2:
                # print 'cycle check fail for component', component, 'degree_cnt', degree_cnt
                return 0

        ret = 1
        # print 'component', component, 'passed cycle check.' 
        for c in component:
            # print '  homo_count[%d] = %d' % (c, homo_count[c])
            ret *= factorial(homo_count[c])
            ret %= MOD

        return ret

    seen = [False] * 26
    ret = 1
    components = 0
    for i in xrange(26):
        if not seen[i] and i in has:
            component = []
            dfs(i, component)
            sol = solveFor(component)
            # print 'started from', i, 'component', component, '=>', sol
            ret *= sol
            ret %= MOD
            components += 1

    ret *= factorial(components)
    ret %= MOD

    return ret

if __name__ == '__main__':
    rl = raw_input
    cases = int(rl())
    for cc in xrange(cases):
        n = int(rl())
        trains = rl().strip().split()
        ret = solve(trains)
        print 'Case #%d: %d' % (cc+1, ret)
