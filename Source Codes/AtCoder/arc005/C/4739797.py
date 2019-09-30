from collections import deque

H,W = map(int,input().split())
c = [['@'] * (W+2) for i in range(H+2)]
for h in range(H):
    C = input()
    for w in range(W):
        c[h+1][w+1] = C[w]
        if C[w] == 's':
            s = [h+1,w+1]

cnt = [[0] * (W+2) for i in range(H+2)]

def bfs(sy,sx):
    dxy = [(1, 0), (0, 1), (-1, 0), (0, -1)]
    queue = deque()
    queue1 = deque()
    queue2 = deque()
    queue.append([sy,sx])
    while queue:
        y,x = queue.popleft()
        for dx,dy in dxy:
            if c[y+dy][x+dx] == '.' and cnt[y+dy][x+dx] == 0:
                queue.append([y+dy,x+dx])
                cnt[y+dy][x+dx] += 1
            elif c[y+dy][x+dx] == '#' and cnt[y+dy][x+dx] == 0:
                queue1.append([y+dy,x+dx])
                cnt[y+dy][x+dx] += 1
            elif c[y+dy][x+dx] == 'g': return "YES"
    while queue1:
        y,x = queue1.popleft()
        for dx,dy in dxy:
            if c[y+dy][x+dx] == '.' and cnt[y+dy][x+dx] == 0:
                queue1.append([y+dy,x+dx])
                cnt[y+dy][x+dx] += 1
            elif c[y+dy][x+dx] == '#' and cnt[y+dy][x+dx] == 0:
                queue2.append([y+dy,x+dx])
                cnt[y+dy][x+dx] += 1
            elif c[y+dy][x+dx] == 'g': return "YES"
    while queue2:
        y,x = queue2.popleft()
        for dx,dy in dxy:
            if c[y+dy][x+dx] == '.' and cnt[y+dy][x+dx] == 0:
                queue2.append([y+dy,x+dx])
                cnt[y+dy][x+dx] += 1
            elif c[y+dy][x+dx] == 'g': return "YES"
    return "NO"

print(bfs(s[0],s[1]))