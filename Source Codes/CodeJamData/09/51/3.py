#!/usr/bin/python

# google code jam - c.durr - 2009

# EZ-Sokoban
#

try:
    import psyco
except:
    pass

def readint():    return int(raw_input())
def readarray(f): return map(f, raw_input().split())

def dangerous(conf):
    p = conf[0]
    mark = set([p])
    Q    = [p]
    while Q:
        (i,j) = Q.pop()        
        for p in [(i-1,j),(i+1,j),(i,j-1),(i,j+1)]:
            if p in conf and not p in mark:
                mark.add(p)
                Q.append(p)
    return len(mark)<len(conf)

def neighbor_nodes(x):
    global board, R, C
    # build choices
    co = conf(x)
    daco = dangerous(co)
    N = [] 
    for (i,j) in co:
        for (di,dj) in [(-1,0),(+1,0),(0,-1),(0,+1)]:
            before = (i-di,j-dj)
            after  = (i+di,j+dj)
            if before in board and (not before in co) \
                    and after in board and (not after in co):
                opt = co[:]
                opt.remove((i,j))
                opt.append(after)                                
                if not dangerous(opt) or not daco:
                    N.append(node(opt))
    return N
                    
def dist(x,y):
    a = conf(x)
    b = conf(y)
    return len(set(a) ^ set(b))

def node(conf):
    global R,C
    base = R*C+1
    n = 0
    conf.sort()
    for (i,j) in conf:
        n = base*n + C*i+j + 1
    return n

def conf(n):
    global R,C
    c = []
    base = R*C+1
    while n>0:
        m = (n % base) - 1
        n /= base
        j = m % C
        i = m / C
        c.append((i,j))
    return c

def Astar(start,goal):
    closedset = set()
    openset   = set([start])
    g_score   = {start: 0 }
    h_score   = {start: dist(start, goal) }
    f_score   = {start: h_score[start]}
    while openset:
        (val, x) = min([(f_score[c],c) for c in openset])
        if x==goal:
            return g_score[x]
        openset.remove(x)
        closedset.add(x)
        
        for y in neighbor_nodes(x):
            if not y in closedset and not y in openset:
                openset.add(y)
                g_score[y] = g_score[x] + 1
                h_score[y] = dist(y, goal)
                f_score[y] = g_score[y] + h_score[y]
    return -1


for test in range(readint()):
    global R,C,board
    R, C = readarray(int)
    M = []
    for _ in range(R):
        M.append(raw_input())

    goal = []
    start = []
    board = []
    for i in range(R):
        for j in range(C):
            c= M[i][j]
            if c=='x':
                goal.append((i,j))
            elif c=='w':
                goal.append((i,j))
                start.append((i,j))
            elif c=='o':
                start.append((i,j))
            if c!='#':
                board.append((i,j))

    print "Case #%i:"% (test+1), Astar(node(start), node(goal))
    
    
