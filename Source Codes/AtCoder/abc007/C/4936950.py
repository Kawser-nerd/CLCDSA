from queue import Queue
r,c = map(int,input().split())
sy,sx = map(int,input().split())
gy,gx = map(int,input().split())
cell_list = [list(input()) for _ in range(r)]

inf = 100000000
d = [[inf for _ in range(c)] for _ in range(r)]
dx = [1,0,-1,0]
dy = [0,1,0,-1]

def bfs():
    q = Queue()
    q.put((sy-1,sx-1))
    d[sy-1][sx-1] = 0

    while not q.empty():
        qy,qx = q.get()
        if qx == gx-1 and qy == gy-1:
            break
        for i in range(4):
            nx = qx + dx[i]
            ny = qy + dy[i]
            try:
                if 0 <= ny and ny < r and 0 <= nx  and cell_list[ny][nx] != '#' and d[ny][nx] == inf:
                    q.put((ny,nx))
                    d[ny][nx] = d[qy][qx]+1
            except IndexError:
                pass
    return d[gy-1][gx-1]

print(bfs())