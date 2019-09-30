# networkx can be installed through pip


import sys
sys.path.append('/Users/horban/anaconda//pkgs/networkx-1.8.1-py27_0/lib/python2.7/site-packages/')
import networkx


def solve(W, H, Bseq):
    mp = [[False] * H for _ in range(W)]

    for x0, y0, x1, y1 in Bseq:
        for x in range(x0, x1+1):
            for y in range(y0, y1+1):
                mp[x][y] = True

    G = networkx.DiGraph()

    def neigh(x, y):
        for ox, oy in [(-1, 0), (1, 0), (0, 1), (0, -1)]:
            nx = ox + x
            ny = oy + y
            if 0 <= nx < W and 0 <= ny < H:
                yield nx, ny

    for x in range(W):
        for y in range(H):
            if not mp[x][y]:
                G.add_edge(hash(('in', x, y)), hash(('out', x, y)), capacity=1)
                for nx, ny in neigh(x, y):
                    if not mp[nx][ny]:
                        G.add_edge(hash(('out', x, y)), hash(('in', nx, ny)), capacity=1000000)

    for x in range(W):
        G.add_edge(hash('src'), hash(('in', x, 0)), capacity=1)
    for x in range(W):
        G.add_edge(hash(('out', x, H-1)), hash('snk'), capacity=1000000)

    flow = networkx.max_flow(G, hash('src'), hash('snk'))
    return int(flow)

import sys
infname = sys.argv[1]
with open(infname) as inf:
    with open(infname.replace('.in', '.out'), 'w') as outf:
        T = int(inf.readline())
        for t in range(1, T+1):
            W,H,B = map(int, inf.readline().split())
            Bseq = [map(int, inf.readline().split())
                    for _ in range(B)]
            outf.write('Case #{}: {}\n'.format(t,solve(W,H,Bseq)))
            print 'Case ', t