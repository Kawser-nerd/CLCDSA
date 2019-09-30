from heapq import heapify, heappush, heappop

n = int(input())
x_loc, y_loc = [], []
for i in range(n):
    x, y = map(int, input().split())
    x_loc.append((x, i))
    y_loc.append((y, i))
x_loc.sort()
y_loc.sort()
links = [set() for _ in range(n)]
for (x1, i1), (x2, i2) in zip(x_loc, x_loc[1:]):
    dist = abs(x1 - x2)
    links[i1].add((dist, i2))
    links[i2].add((dist, i1))
for (y1, i1), (y2, i2) in zip(y_loc, y_loc[1:]):
    dist = abs(y1 - y2)
    links[i1].add((dist, i2))
    links[i2].add((dist, i1))

visited = {0}
queue = list(links[0])
heapify(queue)
total = 0
while True:
    cost, i = heappop(queue)
    if i in visited:
        continue
    visited.add(i)
    total += cost
    if len(visited) == n:
        break
    for cost2, j in links[i]:
        if j in visited:
            continue
        heappush(queue, (cost2, j))
print(total)