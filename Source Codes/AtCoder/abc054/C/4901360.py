from collections import defaultdict
vertices, edges = map(int, input().split(" "))
connect = defaultdict(set)
for i in range(edges):
    a, b = map(int, input().split(" "))
    connect[a] |= {b}
    connect[b] |= {a}

answer = 0
queue = [[set(), 1]]
while queue:
    visited, now = queue.pop()
    visited |= {now}
    # print(visited, now, need_visit)
    if len(visited) == vertices:
        answer += 1
    else:
        for conn in connect[now]:
            if conn not in visited:
                queue.append([visited | {conn}, conn])
        # print(visited, now, need_visit)

print(answer)