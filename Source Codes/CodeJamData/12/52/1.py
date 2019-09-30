import sys


DX = [1, 0, -1, -1, 0, 1]
DY = [1, 1, 0, -1, -1, 0]
D = zip(DX, DY)
numbits = [0, 1, 1, 2, 1, 2, 2, 3, 1, 2, 2, 3, 2, 3, 3, 4, 1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5, 1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5, 2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6]


def corner(S, m):
    if m == (1, 1): return 1
    if m == (1, S): return 2
    if m == (S, 2 * S - 1): return 4
    if m == (2 * S - 1, 2 * S - 1): return 8
    if m == (2 * S - 1, S): return 16
    if m == (S, 1): return 32
    return 0


def edge(S, m):
    if m[0] == 1: return 1
    if m[1] - m[0] == S - 1: return 2
    if m[1] == 2 * S - 1: return 4
    if m[0] == 2 * S - 1: return 8
    if m[0] - m[1] == S - 1: return 16
    if m[1] == 1: return 32
    return 0


def closespath(x):
    found = set()
    for i in xrange(len(x)):
        if x[i] == -1:
            continue
        if x[i] == x[(i + 5) % 6]:
            continue
        if x[i] in found:
            return True
        found.add(x[i])
    return False


def root(parents, i):
    while parents[i] != i:
        i = parents[i]
    return i


def compute(S, moves):
    board = {}
    edges = []
    corners = []
    parents = range(len(moves))
    move = 0
    for m in moves:
        move += 1
        y = []
        result = []
        for d in D:
            m1 = (m[0] + d[0], m[1] + d[1])
            if m1 in board:
                y.append(root(parents, board[m1]))
            else:
                y.append(-1)
        x = set(y)
        x.discard(-1)
        x = list(x)
        for i in xrange(1, len(x)):
            parents[x[i]] = x[0]
            edges[x[0]] |= edges[x[i]]
            corners[x[0]] |= corners[x[i]]
        if len(x) > 0:
            board[m] = x[0]
        else:
            board[m] = len(edges)
            edges.append(0)
            corners.append(0)
        current = board[m]
        c = corner(S, m)
        if c > 0:
            corners[current] |= c
        else:
            e = edge(S, m)
            edges[current] |= e
        if numbits[corners[current]] >= 2:
            result.append('bridge')
        if numbits[edges[current]] >= 3:
            result.append('fork')
        if closespath(y):
            result.append('ring')
        if result:
            return "%s in move %d" % ('-'.join(result), move)
    return 'none'


def parse():
    S, M = map(int, sys.stdin.readline().strip().split())
    moves = []
    for i in xrange(M):
        moves.append(tuple(map(int, sys.stdin.readline().strip().split())))
    return S, moves


if __name__ == "__main__":
    sys.setrecursionlimit(100000)
    T = int(sys.stdin.readline().strip())
    count = 1
    part = 0
    if len(sys.argv) == 3:
        part = int(sys.argv[1])
        count = int(sys.argv[2])
    for i in xrange(T):
        data = parse()
        if i * count >= part * T and i * count < (part + 1) * T:
            result = compute(*data)
            print "Case #%d: %s" % (i + 1, result)
