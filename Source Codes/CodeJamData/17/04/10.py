#!/usr/bin/env python3

from collections import defaultdict
from operator import itemgetter

class Edge:
    def __init__(self, u, v, cap):
        self.source = u
        self.target = v
        self.capacity = cap


class FlowSolver:
    def __init__(self):
        self.adj = defaultdict(list)
        self.flow = defaultdict(int)

    def append(self, u, v, cap):
        self.adj[u].append(Edge(u, v, cap))
        self.adj[v].append(Edge(v, u, 0))  # XXX

    def find_path(self, u, v):
        def iter(u, v, path, visited):
            if u == v:
                return path

            if u in visited:
                assert False
                return []
            visited.add(u)

            for c in self.adj[u]:
                if c.target in visited:
                    continue

                residue = c.capacity - self.flow[(u, c.target)] + self.flow[(c.target, u)]
                if residue <= 0:
                    continue

                ret = iter(c.target, v, path + [((u, c.target), residue)], visited)
                if ret:
                    return ret
            return []

        return iter(u, v, [], set())


    def solve(self, u, v):
        while True:
            path = self.find_path(u, v)
            if not path:
                break
            delta = min(map(itemgetter(1), path))

            for (f, t), _ in path:
                flow = self.flow[(f, t)] - self.flow[(t, f)] + delta
                self.flow[(f, t)] = max(0, flow)
                self.flow[(t, f)] = max(0, -flow)


def solve_bishop(N, old_gene):
    solver = FlowSolver()

    solved_rows = set()
    solved_cols = set()
    for x in range(N ** 2):
        r, c = (x // N), (x % N)
        if old_gene[x] in ['x', 'o']:
            solved_rows.add(r)
            solved_cols.add(c)

    # source -> row (bishop)
    for r in range(N):
        if r not in solved_rows:
            solver.append('source', ('row', r), 1)

    # row -> column (bishop)
    for x in range(N ** 2):
        if old_gene[x] in ['x', 'o']:
            continue
        r, c = (x // N), (x % N)
        if r not in solved_rows and c not in solved_cols:
            solver.append(('row', r), ('col', c), 1)

    # column -> sink (bishop)
    for c in range(N):
        if c not in solved_cols:
            solver.append(('col', c), 'sink', 1)

    # make it flow!
    solver.solve('source', 'sink')

    bishops = set()
    for (f, t), v in solver.flow.items():
        if v <= 0 or f == 'source' or t == 'sink':
            continue
        (rtag, r), (ctag, c) = f, t

        assert(rtag == 'row' and ctag == 'col')
        bishops.add(r * N + c)
    return bishops


def solve_rook(N, old_gene):
    solver = FlowSolver()

    solved_a45 = set()
    solved_a135 = set()
    for x in range(N ** 2):
        r, c = (x // N), (x % N)
        if old_gene[x] in ['+', 'o']:
            solved_a45.add(r + c)
            solved_a135.add(r + (N-1-c))

    # source -> A45 (rook)
    for x in range(N * 2 - 1):
        if x not in solved_a45:
            solver.append('source', ('A45', x), 1)

    # A45 -> A135 (rook)
    for x in range(N ** 2):
        if old_gene[x] in ['+', 'o']:
            continue
        r, c = (x // N), (x % N)
        a45 = r + c
        a135 = r + (N-1-c)
        if a45 not in solved_a45 and a135 not in solved_a135:
            solver.append(('A45', a45), ('A135', a135), 1)

    # A135 -> sink (rook)
    for x in range(N * 2 - 1):
        if x not in solved_a135:
            solver.append(('A135', x), 'sink', 1)

    # make it flow!
    solver.solve('source', 'sink')

    rooks = set()
    for (f, t), v in solver.flow.items():
        if v <= 0 or f == 'source' or t == 'sink':
            continue
        (atag, a), (btag, b) = f, t

        assert(atag == 'A45' and btag == 'A135')
        r = (a + b - (N-1)) // 2
        c = (a - b + (N-1)) // 2
        rooks.add(r * N + c)
    return rooks


def solve(N, old_gene):
    bishops = solve_bishop(N, old_gene)
    rooks = solve_rook(N, old_gene)
    
    new_gene = list(old_gene)
    for x in bishops:
        new_gene[x] = 'xo'[new_gene[x] in ['+', 'o']]
    for x in rooks:
        new_gene[x] = '+o'[new_gene[x] in ['x', 'o']]
    return new_gene


def points(gene):
    return gene.count('+') + gene.count('x') + gene.count('o') * 2


def diff(N, old_gene, new_gene):
    assert len(old_gene) == len(new_gene) == (N ** 2)
    changes = []

    for x in range(len(new_gene)):
        o = old_gene[x]
        n = new_gene[x]
        if o == n:
            continue
        r = x // N
        c = x % N
        changes.append((n, r, c))
    return changes


T = int(input())

for case_number in range(1, T+1):
    N, M = map(int, input().split())
    old_gene = ['.'] * (N * N)
    for m in range(M):
        t, r, c = input().split()
        r = int(r) - 1  # 0-based
        c = int(c) - 1
        old_gene[r * N + c] = t

    new_gene = solve(N, old_gene)
    point = points(new_gene)
    changes = diff(N, old_gene, new_gene)

    print('Case #%d:' % case_number, point, len(changes))
    for t, r, c in changes:
        r += 1  # 1-based
        c += 1
        print(t, r, c)
