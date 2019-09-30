import sys
import heapq
height, width = map(int, sys.stdin.readline().split(" "))
nesw = [[0, 1], [0, -1], [1, 0], [-1, 0]]
root = []
start_x, start_y, end_x, end_y = -1, -1, -1, -1
for h in range(height):
    temp = sys.stdin.readline()
    root.append([n for n in temp])
for h in range(height):
    for w in range(width):
        if root[h][w] == "s":
            start_x, start_y = w, h
        elif root[h][w] == "g":
            end_x, end_y = w, h
queue = []
heapq.heappush(queue, (0, (start_x, start_y)))
visited = [[0 for n in range(width)] for m in range(height)]

while queue:
    point, (x, y) = heapq.heappop(queue)
    if visited[y][x]:
        continue
    visited[y][x] = 1
    if y == end_y and x == end_x:
        break
    for t in nesw:
        new_x, new_y = x + t[0], y + t[1]
        if 0 <= new_y < height and 0 <= new_x < width and not visited[new_y][new_x]:
            temp_point = point + int(root[new_y][new_x] == "#")
            if temp_point <= 2:
                heapq.heappush(queue, (temp_point, (new_x, new_y)))

if visited[end_y][end_x]:
    print("YES")
else:
    print("NO")