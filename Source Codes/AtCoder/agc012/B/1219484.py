from queue import deque


def paint(s, d, c):
    queue = deque([(d, s)])
    while queue:
        remains, v = queue.popleft()
        if painted[v] >= remains:
            continue
        if colors[v] == 0:
            colors[v] = c
        painted[v] = remains
        if remains:
            queue.extend((remains - 1, u) for u in links[v])


n, m = map(int, input().split())
links = [None] + [set() for _ in range(n)]
for _ in range(m):
    a, b = map(int, input().split())
    links[a].add(b)
    links[b].add(a)

q = int(input())
queries = [map(int, input().split()) for _ in range(q)]
colors = [0] * (n + 1)
painted = [-1] * (n + 1)
while queries:
    paint(*queries.pop())

for c in colors[1:]:
    print(c)