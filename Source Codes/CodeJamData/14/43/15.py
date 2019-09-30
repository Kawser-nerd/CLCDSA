import sys
import os
sys.path.insert(0, os.path.expanduser("~/../../Python27/Lib/site-packages"))
import networkx as nx
#print "Succ"
t = input()

def make_grid(buildings):
    g = [[1]*h for _ in xrange(w)]
    for x0, y0, x1, y1 in buildings:
        for y in range(y0, y1+1):
            for x in range(x0, x1+1):
                g[x][y] = 0
    return g

def in_building(x, y):
    for b in buildings:
        if
    
def adj(g, x, y):
    l = []
    if x-1 >= 0 and g[x-1][y]:
        l.append((x-1, y))
    if y-1 >= 0 and g[x][y-1]:
        l.append((x, y-1))
    if x+1 <= w-1 and g[x+1][y]:
        l.append((x+1, y))
    if y+1 <= h-1 and g[x-1][y]:
        l.append((x-1, y))
    return l
    
def name(x,y):
    return "%d-%d" % (x, y)
    
def min_cut(grid):
    G = nx.DiGraph()
    #node name:
    # x-y-(in|out)
    for x in range(w):
        for y in range(h):
            if not grid[x][y]:
                continue
            ad = adj(grid, x, y)
            for a in ad:
                G.add_edge(name(*a)+"-out", name(x,y)+"-in", capacity=1)
                G.add_edge(name(x,y)+"-in", name(x,y)+"-out", capacity=1)
                G.add_edge(name(x,y)+"-out", name(*a)+"-in", capacity=1)
    # supernodes
    for x in range(w):
        if grid[x][0]:
            G.add_edge("start", name(x,0)+"-in", capacity=1)
        if grid[x][h-1]:
            G.add_edge(name(x,h-1)+"-out", "end", capacity=1)
    if "start" not in G or "end" not in G:
        return 0
    return nx.min_cut(G, 'start', 'end')
    

for case in xrange(1, t+1):
    w, h, b = map(int, raw_input().split())
    buildings = [map(int, raw_input().split()) for _ in xrange(b)]
    print "Case #%d: %d" % (case, min_cut(make_grid(buildings)))