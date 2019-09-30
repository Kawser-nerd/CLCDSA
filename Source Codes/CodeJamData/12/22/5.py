from heapq import *

INFINITY = 100000000

def can_move(uf,uc,vf,vc,ch):
    if ch > vc - 50:
        return False
    if uf > vc - 50:
        return False
    if vf > vc - 50:
        return False

    if vf > uc - 50:
        return False

    return True

def best_time(uf,uc,vf,vc,ch):
    if uf > vc - 50:
        return INFINITY
    if vf > vc - 50:
        return INFINITY

    if vf > uc - 50:
        return INFINITY

    maxch = vc - 50
    timeused = 0
    if ch > maxch:  # can't move
        timeused += ch - maxch
        ch = maxch
        
    if ch >= uf + 20:
        return timeused + 10
    else:
        return timeused + 100


def free_move():
    global n,m,h,f,c

    d = {}
    for i in range(n):
        for j in range(m):
            d[(i,j)] = INFINITY
    d[(0,0)] = 0

    #free_move(d)

    visited = set()
    q = []
    q.append((0,0))
    while len(q)!=0:
        ui,uj = q[0]

        del q[0]
        
        if (ui,uj) in visited:
            continue

        visited.add((ui,uj))
        d[(ui,uj)] = 0

        for di,dj in [(-1,0),(0,1),(1,0),(0,-1)]:
            vi = ui + di
            vj = uj + dj

            if (vi < 0) or (vi >= n) or (vj < 0) or (vj >= m):
                continue

            if can_move(f[(ui,uj)],c[(ui,uj)],
                        f[(vi,vj)],c[(vi,vj)],
                        h):
                q.append((vi,vj))

    return d

def dj(t):
    global n,m,h,f,c

    d = free_move()

    s = set()

    Q = []
    for i in range(n):
        for j in range(m):
            if d[(i,j)]==0:
                heappush(Q,(0,(i,j)))

    visited = set()

    while (n-1,m-1) not in s:

        dd,u = heappop(Q)
        ui,uj = u

        if (ui,uj) in visited:
            continue
        visited.add((ui,uj))

        for di,dj in [(-1,0),(0,1),(1,0),(0,-1)]:
            vi = ui + di
            vj = uj + dj

            if (vi < 0) or (vi >= n) or (vj < 0) or (vj >= m):
                continue

            if (vi,vj) in s:
                continue

            ud = d[(ui,uj)]
            ch = h - ud

            new_dv = ud + best_time(f[(ui,uj)],c[(ui,uj)],
                                    f[(vi,vj)],c[(vi,vj)],
                                    ch)

            if new_dv < d[(vi,vj)]:
                d[(vi,vj)] = new_dv
                heappush(Q,(new_dv,(vi,vj)))

        s.add((ui,uj))

    print ("Case #%d:" % t), float(d[(n-1,m-1)])/10.0

def read_input():
    global n,m,h,f,c

    h,n,m = [int(x) for x in raw_input().strip().split()]
    f = {}
    c = {}

    for i in range(n):
        xx = [int(x) for x in raw_input().strip().split()]
        for j in range(m):
            c[(i,j)] = xx[j]

    for i in range(n):
        xx = [int(x) for x in raw_input().strip().split()]
        for j in range(m):
            f[(i,j)] = xx[j]

def solve(t):
    read_input()
    dj(t)


def main():
    t = int(raw_input())
    for i in range(t):
        solve(i+1)

if __name__=='__main__':
    main()

