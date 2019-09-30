D = [(-1,0), (1,0), (0,1), (0, -1)]

def solve():
    h, n, m = map(int, raw_input().split())
    c = [map(int, raw_input().split()) for _ in xrange(n)]
    f = [map(int, raw_input().split()) for _ in xrange(n)]

    t = [[10**9]*m for _ in xrange(n)]
    t[0][0] = 0
    q = set([(0,0)])
    vis = q.copy()
    while q:
        x, y = next(iter(q))
        for xx,yy in q:
            if t[xx][yy] < t[x][y]:
                x, y = xx, yy
        if x == n-1 and y == m-1: break
        vis.add((x,y))
        q.remove((x,y))
        te = max(0, h - f[x][y] - 20)
        for dx,dy in D:
            nx, ny = x + dx, y + dy
            if nx<0 or ny <0 or nx >=n or ny >=m: continue
            if (nx,ny) in vis: continue
            if min(c[nx][ny],c[x][y])-max(f[nx][ny],f[x][y])<50: continue
            tw = max(0, h - c[nx][ny] + 50)
            tn = max(t[x][y],tw)
            #            print nx, ny, tw, te, tn
            if tn > 0:
                if tn > te: tn += 100
                else: tn += 10
            t[nx][ny] = min(t[nx][ny], tn)
            q.add((nx,ny))

    return t[n-1][m-1]

t = input()
for i in xrange(t):
    a = solve()
    print "Case #%d: %d.%d"%(i+1, a/10, a%10)
