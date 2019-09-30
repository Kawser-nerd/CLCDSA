import sys

def add_adj(x,y,grid,H,reachable):
    g, c = grid[x][y]
    for dx,dy in [(0,1), (1,0), (-1, 0), (0, -1)]:
        if x + dx < 0 or x + dx >= len(grid):
            continue
        if y + dy < 0 or y + dy >= len(grid[0]):
            continue
        gn,cn = grid[x+dx][y+dy]
        if gn <= cn-50 and H <= cn-50 and cn - g >= 50 and c - gn >= 50:
            reachable.add((x+dx,y+dy))

def add_initial(grid, cloud, H):
    reachable = set()
    add_adj(0,0,grid,H,reachable)
    while reachable:
        x,y = reachable.pop()
        if (x,y) in cloud:
            continue
        add_adj(x,y,grid,H,reachable)
        cloud[(x,y)] = 0
        

def solve(grid, H):
    cloud = {(0,0):0}
    reachable = {}
    ex = len(grid)-1
    ey = len(grid[0])-1
    add_initial(grid, cloud, H)
    reachable = set()
    for x,y in cloud.keys():
        for adj in ((x+1,y),(x,y+1),(x-1,y),(x,y-1)):
            a,b = adj
            if a < 0 or a > ex:
                continue
            if b < 0 or b > ey:
                continue
            if a,b in cloud:
                continue
            reachable.add((a,b))
            
    while True:
        tmin = None
        for k in reachable:
            x,y = k
            t = cloud[(x,y)]
            g,c = grid[x][y]
            wl = H - (t*10)
            
            for adj in ((x+1,y),(x,y+1),(x-1,y),(x,y-1)):
                if adj in cloud:
                    continue
                a,b = adj
                if a < 0 or a > ex:
                    continue
                if b < 0 or b > ey:
                    continue
                
                gn,cn = grid[a][b]
                if cn - gn < 50:
                    continue
                if (cn - g) < 50:
                    continue
                if c - gn < 50:
                    continue
                
                awl = wl
                if cn - awl < 50:
                    awl = cn - 50

                delay = (wl - awl)/10.
                    
                if awl - g >= 20:
                    tn = t + 1 + delay
                else:
                    tn = t + 10 + delay
                if tmin is None or tn < tmin:
                    tmin = tn
                    xn = a
                    yn = b
        cloud[(xn,yn)] = tmin


if __name__=="__main__":
    T = int(raw_input())
    for i in range(1, T+1):
        H,N,M = map(int, raw_input().split())
        grid = []
        for a in range(N):
            grid.append([])
            for b in range(M):
                grid[-1].append([])

        for a in range(2):
            for j in range(N):
                values = map(int, raw_input().split())
                for k,v in enumerate(values):
                    grid[j][k].insert(0, v)
        # print H
        # print "\n".join(map(str, grid))
        out = "Case #%d: %f" % (i, solve(grid, H))
        print out
        sys.stderr.write(out + "\n")
        
        
