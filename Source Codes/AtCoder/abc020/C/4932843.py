import heapq
H,W,T = map(int, input().split())
maze = [input() for _ in range(H)]
for y in range(H):
    for x in range(W):
        if maze[y][x]=="S":
            sx,sy = x,y
        if maze[y][x]=="G":
            gx,gy = x,y

INF = float('inf')
dxy = [(0,1), (1,0), (0,-1), (-1,0)]

def bfs(k:int)->bool:
    hq = [(0, sx, sy)] # time, x, y
    heapq.heapify(hq)
    dist = [[INF]*W for _ in range(H)]
    while hq:
        t,x,y = heapq.heappop(hq)
        if t > T: break
        if x==gx and y==gy: return True
        for dx,dy in dxy:
            nx,ny = x+dx,y+dy
            if not (0<=nx<W and 0<=ny<H): continue
            d = k if maze[ny][nx]=="#" else 1
            if t+d >= dist[ny][nx]: continue
            dist[ny][nx] = t+d
            heapq.heappush(hq, (t+d, nx, ny))
    return False


def binary_search(f, s:int, t:int)->int:
    """f: function(x:int)->bool
    f(t): NG(False), f(s)=OK(True)?f ???????
    return : [s, t) ?? f(x)=True ??'??'?x
    """
    ng = t
    ok = s-1
    while ng - ok > 1:
        mid = (ok + ng)//2
        if f(mid): ok = mid
        else:      ng = mid
        # print(ng, ok, ok-ng)

    if ok==t:
        raise(ValueError("For all x, f(x)=False"))
    return ok

print(binary_search(bfs, 2, 10**10))