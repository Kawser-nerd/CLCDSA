import heapq


class Dijkstra:

    def __init__(self, rote_map, start_point, wall_cost, goal_point=None):
        self.rote_map = rote_map
        self.start_point = start_point
        self.goal_point = goal_point
        self.wall_cost = wall_cost

    def execute(self):
        num_of_city = len(self.rote_map)
        dist = [float("inf") for _ in range(num_of_city)]
        prev = [float("inf") for _ in range(num_of_city)]

        dist[self.start_point] = 0
        heap_q = []
        heapq.heappush(heap_q, (0, self.start_point))
        route_count = [0 for _ in range(num_of_city)]
        route_count[self.start_point] = 1
        while len(heap_q) != 0:
            prev_cost, src = heapq.heappop(heap_q)

            if dist[src] < prev_cost:
                continue

            for dest, cost in self.rote_map[src].items():
                if cost == float("inf"):
                    cost = self.wall_cost
                if cost != float("inf") and dist[dest] > dist[src] + cost:
                    dist[dest] = dist[src] + cost
                    heapq.heappush(heap_q, (dist[dest], dest))
                    prev[dest] = src
                if dist[dest] == dist[src] + cost:
                    route_count[dest] += route_count[src]

        if self.goal_point is not None:
            return self._get_path(self.goal_point, prev)
        else:
            return dist, route_count

    def _get_path(self, goal, prev):
        path = [goal]
        dest = goal

        while prev[dest] != float("inf"):
            path.append(prev[dest])
            dest = prev[dest]

        return list(reversed(path))


h, w, t = map(int, input().split())
s_list = []
for i in range(h):
    s_list.append(input())

route = [dict() for _ in range(w * h)]
start = -1
goal = -1

for i in range(h):
    s = s_list[i]
    if s.count("S") == 1:
        j = s.index("S")
        start = w * i + j
    if s.count("G") == 1:
        j = s.index("G")
        goal = w * i + j

    for j in range(w - 1):
        wall = s[j + 1]
        cost_n = 0
        if wall == "#":
            cost_n = float("inf")
        else:
            cost_n = 1
        wall = s[j]
        cost_b = 0
        if wall == "#":
            cost_b = float("inf")
        else:
            cost_b = 1
        route[w * i + j][w * i + j + 1] = cost_n
        route[w * i + j + 1][w * i + j] = cost_b

    if i != h - 1:
        for j in range(w):
            nex = s_list[i + 1]
            wall = nex[j]
            cost_n = 0
            if wall == "#":
                cost_n = float("inf")
            else:
                cost_n = 1
            wall = s[j]
            cost_b = 0
            if wall == "#":
                cost_b = float("inf")
            else:
                cost_b = 1
            route[w * i + j][w * (i + 1) + j] = cost_n
            route[w * (i + 1) + j][w * i + j] = cost_b
lo = 1
hi = t
while hi - lo >= 0:
    mi = (hi + lo) // 2
    di = Dijkstra(route, start, mi)
    r, p = di.execute()
    if r[goal] <= t:
        lo = mi + 1
    else:
        hi = mi - 1
print((hi+lo)//2)