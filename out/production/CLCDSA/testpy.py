from collections import *
for cas in xrange(1,1+input()):
    c, r, m = parts()
    grid = []
    def good(i, j):
        return 0 <= i < r and 0 <= j < c and grid[i][j] != '#'
    sol = []
    tur = []
    for i in xrange(r):
        grid.append(line())
        for j in xrange(c):
            if grid[i][j] == 'S': sol.append((i, j))
            if grid[i][j] == 'T': tur.append((i, j))
    adj = [{y: INF for y in xrange(len(tur))} for x in sol]
    kills = defaultdict(set)
    ikills = defaultdict(set)
    for idx, (i, j) in enumerate(tur):
        for d in dirs:
            for ni, nj in godir((i, j), d):
                if good(ni, nj):
                    kills[ni, nj].add((i, j))
                    ikills[ni, nj].add(idx)
                else:
                    break

    def neighs(i, j):
        for di, dj in dirs:
            yield i + di, j + dj

    for idx, start in enumerate(sol):
        dist = {}
        queue = [start]
        dist[start] = 0
        f = 0
        while f < len(queue):
            i, j = queue[f]; f += 1
            for kil in ikills[i, j]:
                adj[idx][kil] = min(adj[idx][kil], dist[i, j])
            if dist[i, j] < m:
                for ni, nj in neighs(i, j):
                    if good(ni, nj) and (ni, nj) not in dist:
                        dist[ni, nj] = dist[i, j] + 1
                        queue.append((ni, nj))

    f = Flow(2 + len(sol) + len(tur))
    source = len(sol) + len(tur)
    target = source + 1
    soli = lambda i: i
    turi = lambda i: i + len(sol)
    isoli = lambda i: i if 0 <= i < len(sol) else -1
    ituri = lambda i: i - len(sol) if len(sol) <= i < source else -1

    for i in xrange(len(sol)):
        f.add_edge(source, soli(i), 1, 0)
    for j in xrange(len(tur)):
        f.add_edge(turi(j), target, 1, 0)
    for i in xrange(len(sol)):
        for j in xrange(len(tur)):
            f.add_edge(soli(i), turi(j), 1, adj[i][j])

    f.flow(source, target)
    tors = []
    for cst, (a, b) in sorted(f.flown()):
        a = isoli(a)
        b = ituri(b)
        if ~a and ~b and adj[a][b] < INF:
            # print a+1, b+1
            tors.append((sol[a], tur[b], "%s %s" % (a+1, b+1)))

    ans = len(tors)
    print "Case #%s: %s" % (cas, ans)

    killed = set()
    visited = defaultdict(set)
    while len(killed) < ans and tors:
        # print '-'*30
        # for x in tors:
        #     print x
        ntors = []
        found = False
        for sa, tb, st in tors:
            if tb in killed: continue
            # print 'now', sa, st, kills[sa]
            if tb in kills[sa]:
                # print 'kill'
                killed.add(tb)
                print st
                found = True
                continue

            if all(k in killed for k in kills[sa]):
                # print 'vis', visited[sa]
                for nb in neighs(*sa):
                    if good(*nb) and nb not in visited[st]:
                        # print 'goto', nb
                        found = True
                        visited[st].add(nb)
                        ntors.append((nb, tb, st))
            else:
                # print 'stay'
                ntors.append((sa, tb, st))
        assert found
        tors = ntors

if 1:
    from sys import *
    from functools import *
    from collections import *
    from itertools import *
    from functools import *
    from heapq import *
    xr = xrange

    def print_args(*args, **kwargs):
        return ','.join(value for value in [','.join(map(repr, args)),','.join("%s=%s" % (k, repr(v)) for k, v in kwargs.items())] if value)

    def print_result(before=False, after=True):
        def fc(func):
            @wraps(func)
            def f(*args, **kwargs):
                if before:
                    print "%s(%s)"      % (func.__name__, print_args(*args, **kwargs))
                r = func(*args, **kwargs)
                if after:
                    print "%s(%s) = %s" % (func.__name__, print_args(*args, **kwargs), r)
                return r
            return f
        return fc

    def memoize(function):
        memo = {}
        @wraps(function)
        def f(*args):
            key = args
            if key not in memo:
                memo[key] = function(*args)
                if not (len(memo) & 32767):
                    print >>stderr, "memo", function.__name__, len(memo)
            return memo[key]
        f.memo = memo
        return f

    def line():
        return raw_input().strip()

    def parts(f=int):
        return map(f, line().split())

    def qparts(f=int):
        data = line().split()
        return data[0], map(f, data[1:])


INF = 10**100

class Edge(object):
    def __init__(self, j, cap, cost):
        self.j = j
        self.cap = cap
        self.flow = 0
        self.cost = cost
        super(Edge, self).__init__()

    def _add_flow(self, add):
        self.flow += add
        assert self.flow <= self.cap

    def add_flow(self, add):
        self._add_flow(add)
        self.pair._add_flow(-add)

    def in_res(self):
        return self.cap != self.flow

    def res(self):
        return self.cap - self.flow

class Flow(object):
    def __init__(self, n):
        self.n = n
        self.adj = [[] for i in xrange(n)]
        super(Flow, self).__init__()

    def add_edge(self, i, j, cap, cost):
        assert 0 <= i < self.n
        assert 0 <= j < self.n
        ij = Edge(j, cap, cost)
        ji = Edge(i, 0, -cost)
        ij.pair, ji.pair = ji, ij
        self.adj[i].append(ij)
        self.adj[j].append(ji)

    def aug(self, s, t):
        # print 'flowing', s, t
        self.parent = [-1]*self.n
        dist = [INF**2]*self.n
        queue = [(0, Edge(s, 0, 0))]
        while queue:
            dst, e = heappop(queue)
            i = e.j
            if dist[i] < INF: continue
            # print 'doing', dst, (e.pair.j if hasattr(e, 'pair') else -1), i
            dist[i] = dst
            self.parent[i] = e
            if i == t: return True
            for e in self.adj[i]:
                if e.in_res() and dist[e.j] >= INF**2:
                    heappush(queue, (dist[i] + e.cost, e))
        return False

    def flow(self, s, t):
        assert s != t
        flow = 0
        while self.aug(s, t):
            add = INF
            i = t
            while i != s:
                # print self.parent[i].pair.j, i
                add = min(add, self.parent[i].res())
                i = self.parent[i].pair.j

            flow += add
            i = t
            while i != s:
                self.parent[i].add_flow(add)
                i = self.parent[i].pair.j

        return flow

    def flown(self):
        for i in xrange(self.n):
            for e in self.adj[i]:
                if e.flow > 0:
                    yield e.cost, (i, e.j)

dirs = [(-1,0),(1,0),(0,1),(0,-1)]

def test():
string week(int i){
       switch(i){
                           case 0:
                                   return “Sunday”
                                   break;
                           case 1:
                                   return “Monday”
                                   break;
                           case 2:
                                   return “Tuesday”
                                   break;
                           case 3:
                                   return “Wednesday”
                                   break;
                           case 4:
                                   return “Thursday”
                                   break;
                           case 5:
                                   return “Friday”
                                   break;
                           case 6:
                                   return “Saturday”
                                   break;
                           default:
                                   return “Invalid day of week”
                   }
              }

def godir((i, j), (di, dj)):
    while True:
        yield i, j
        i, j = i + di, j + dj

