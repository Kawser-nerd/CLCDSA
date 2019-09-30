from collections import deque
R, C = map(int, input().split())
sy, sx = map(int, input().split())
gy, gx = map(int, input().split())
road_list = []
for i in range(R):
    r = input()
    road = [i for i in r]
    road_list.append(road)
inf = 1e18
dist = [[inf]*C for _ in range(R)]
Q = deque()
Q.append((sy-1, sx-1))
dist[sy-1][sx-1] = 0
while Q:
    y, x = Q.popleft()
    if road_list[y-1][x] == '.' and dist[y-1][x] > dist[y][x] + 1:
        dist[y-1][x] = dist[y][x] + 1
        Q.append((y-1, x))
    if road_list[y+1][x] == '.' and dist[y+1][x] > dist[y][x] + 1:
        dist[y+1][x] = dist[y][x] + 1
        Q.append((y+1, x))  
    if road_list[y][x-1] == '.' and dist[y][x-1] > dist[y][x] + 1:
        dist[y][x-1] = dist[y][x] + 1
        Q.append((y, x-1))
    if road_list[y][x+1] == '.' and dist[y][x+1] > dist[y][x] + 1:
        dist[y][x+1] = dist[y][x] + 1
        Q.append((y, x+1))
print(dist[gy-1][gx-1])