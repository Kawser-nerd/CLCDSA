h,w = map(int,input().split())
s = [list(input()) for _ in range(h)]
num = 1
dis = [[10**9]*w for _ in range(h)]
cnt = 0
for i in range(len(s)):
    cnt += s[i].count('.')
def bfs():
    queue = []
    done = []
    queue.insert(0,(0,0))
    dis[0][0] = 1

    while len(queue):
        y,x = queue.pop()
        if (y,x) in done:
            continue
        else:
            done.insert(0,(y,x))
        if x==w-1 and y==h-1:
            break

        for i in range(0,4):
            nx,ny = x+[1,0,-1,0][i], y+[0,1,0,-1][i]
            if 0<=nx<w and 0<=ny<h and s[ny][nx]!='#':
                queue.insert(0,(ny,nx))
                dis[ny][nx] = min(dis[ny][nx],dis[y][x]+1)
    return dis[h-1][w-1]
ret = bfs()
if ret==10**9:
    print(-1)
else:
    print(cnt-ret)