import codejam as gcj
import codejam.graphs as gph

T = gcj.read_input('i')
for t in range(T):
    W, H, B, buildings = gcj.read_input('i i i->', 'i[]')
    G = gph.grid_2d_graph(W, H)

    for x in range(W):
        G.add_edge('S', (x, 0))
        G.add_edge('T', (x, H - 1))

    for a, b in G.edges():
        G[a][b]['capacity'] = 1

    for l, b, r, top in buildings:
        for i in range(l, r + 1):
            for j in range(b, top + 1):
                G.remove_node((i, j))

    print 'Case #%i:' % (t + 1), gph.node_connectivity(G, 'S', 'T')