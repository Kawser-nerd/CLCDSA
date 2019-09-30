import heapq
k = int(input())
j = [0] * k
for i in range(k):
    j[i] = [(tuple([(i * 10) % k, 0]))]
    j[i].append(tuple([(i + 1) % k, 1]))

min_cost = [float("inf")] * k
def dijkstra(s):
    queue = [tuple([1, s])]
    while queue:
        p = heapq.heappop(queue)
        for e in j[p[1]]:
            if p[0] + e[1] >= min_cost[e[0]]:
                continue
            min_cost[e[0]] = p[0] + e[1]
            heapq.heappush(queue, tuple([min_cost[e[0]], e[0]]))
dijkstra(1)
print(min_cost[0])