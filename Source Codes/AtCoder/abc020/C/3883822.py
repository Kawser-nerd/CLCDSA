import heapq
H,W,T = map(int,input().split())
src = [input() for i in range(H)]
for y,row in enumerate(src):
    if 'S' in row:
        sy = y
        sx = row.index('S')
    if 'G' in row:
        gy = y
        gx = row.index('G')

INF = float('inf')
dxy = [(0,1),(1,0),(0,-1),(-1,0)]

def reach(k):
    hq = [(0,sx,sy)]
    heapq.heapify(hq)
    dist = [[INF]*W for _ in range(H)]
    while heapq:
        t,x,y = heapq.heappop(hq)
        if t > T: break
        if x==gx and y==gy: return True
        for dx,dy in dxy:
            nx,ny = x+dx,y+dy
            if not 0 <= nx < W: continue
            if not 0 <= ny < H: continue
            d = k if src[ny][nx] == '#' else 1
            if t+d >= dist[ny][nx] : continue
            dist[ny][nx] = t+d
            heapq.heappush(hq,(t+d,nx,ny))
    return False

ok = 1
ng = T+1
while ng-ok > 1:
    m = (ok+ng)//2
    if reach(m):
        ok = m
    else:
        ng = m
print(ok)