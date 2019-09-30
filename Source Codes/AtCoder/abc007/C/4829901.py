from collections import deque
import sys
input = sys.stdin.readline

R, C = map(int, input().split())
sy, sx = map(int, input().split())
gy, gx = map(int, input().split())
c = [list(input()) for _ in range(R)]
dist = [[-1]*C for _ in range(R)]
dist[sy-1][sx-1] = 0
queue = deque()
queue.append([sy-1, sx-1])
dxy = ((-1, 0), (1, 0), (0, -1), (0, 1))

while len(queue) != 0:
    point = queue.popleft()
    py = point[0]
    px = point[1]
    for i in dxy:
        if c[py+i[0]][px+i[1]] == '.' and dist[py+i[0]][px+i[1]] == -1:
            queue.append([py+i[0], px+i[1]])
            dist[py+i[0]][px+i[1]] = dist[py][px] + 1

print(dist[gy-1][gx-1])