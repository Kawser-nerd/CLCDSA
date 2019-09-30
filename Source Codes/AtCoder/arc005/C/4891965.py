from collections import deque
H,W = map(int,input().split())
C = [input() for i in range(H)]

for i,row in enumerate(C):
    if 's' in row:
        sx,sy = row.index('s'),i

q = deque()
q.append((0,sx,sy))
INF = H*W*999
dist = [[INF]*W for i in range(H)]
dxy = [(0,1),(1,0),(0,-1),(-1,0)]

while q:
    d,x,y = q.popleft()
    for dx,dy in dxy:
        nx,ny = x+dx,y+dy
        if not 0 <= nx < W: continue
        if not 0 <= ny < H: continue
        c = 1 if C[ny][nx] == '#' else 0
        if d+c > 2: continue
        if d+c >= dist[ny][nx]: continue
        dist[ny][nx] = d+c
        if C[ny][nx] == 'g':
            print('YES')
            exit()
        if c:
            q.append((d+c,nx,ny))
        else:
            q.appendleft((d,nx,ny))

print('NO')