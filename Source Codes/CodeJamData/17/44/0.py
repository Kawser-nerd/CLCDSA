from sys import stdin, stderr

def getInts():
    return tuple(int(z) for z in stdin.readline().split())

(T,)=getInts()

discreteLog = {1<<i:i for i in xrange(100)}

for tc in xrange(1,1+T):
    (C,R,M) = getInts()
    grid = [stdin.readline().strip() for i in xrange(R)]
    soldiers = [(i,j) for i in xrange(R) for j in xrange(C) if grid[i][j] == 'S']
    turrets = [(i,j) for i in xrange(R) for j in xrange(C) if grid[i][j] == 'T']
    ns = len(soldiers)
    nt = len(turrets)
    print >>stderr, tc, ns, nt, R, C
    states = set([(0,0)])
    statesq = [(0,0)]
    parents = {}
    reach = [set([]) for i in xrange(nt)]
    for i in xrange(nt):
        (tx,ty) = turrets[i]
        reach[i].add((tx,ty))
        for (dx,dy) in [(1,0),(0,1),(-1,0),(0,-1)]:
            (bx,by) = (tx+dx,ty+dy)
            while bx >= 0 and bx < R and by >= 0 and by < C and grid[bx][by] != '#':
                reach[i].add((bx,by))
                (bx,by) = (bx+dx,by+dy)
    rdir = {}
    for i in xrange(nt):
        for (rx,ry) in reach[i]:
            if (rx,ry) in rdir:
                rdir[(rx,ry)].append(i)
            else:
                rdir[(rx,ry)] = [i]
    for (sm,tm) in statesq:
        active = set([])
        for i in xrange(nt):
            if (tm >> i) & 1:
                pass
            else:
                active.add(i)
        for i in xrange(ns):
            if (sm >> i) & 1 == 0:
                (sx,sy) = soldiers[i]
                sq = [(sx,sy,0)]
                sr = set([(sx,sy)])
                canreach = set([])
                for (px,py,pd) in sq:
                    if (px,py) in rdir:
                        v = [z for z in rdir[(px,py)] if z in active]
                        if len(v) > 0:
                            for k in v:
                                canreach.add(k)
                            continue
                    if pd == M:
                        continue
                    for (dx,dy) in [(-1,0),(1,0),(0,-1),(0,1)]:
                        (qx,qy) = (px+dx,py+dy)
                        if qx >= 0 and qx < R and qy >= 0 and qy < C and grid[qx][qy] != '#' and (qx,qy) not in sr:
                            sq.append((qx,qy,pd+1))
                            sr.add((qx,qy))
                for k in canreach:
                    state2 = (sm + (1 << i), tm + (1 << k))
                    if state2 not in states:
                        states.add(state2)
                        statesq.append(state2)
                        parents[state2] = (sm,tm)
    (sf,tf) = statesq[-1]
    x = []
    while (sf,tf) != (0,0):
        (sp,tp) = parents[(sf,tf)]
        x.append([discreteLog[sf-sp], discreteLog[tf-tp]])
        (sf,tf) = (sp,tp)
    print "Case #{}: {}".format(tc,len(x))
    for (i,j) in x[::-1]:
        print "{} {}".format(i+1,j+1)
