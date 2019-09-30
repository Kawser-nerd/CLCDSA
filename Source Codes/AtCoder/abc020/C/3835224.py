import heapq


class dijkstra:
    def __init__(self, adj):
        self.adj = adj
        self.visited = [-1 for i in range(len(adj))]
        self.heap = []

    def allSearch(self, _start):
        # ?????????
        heapq.heappush(self.heap, [0, _start])
        # ??????????????????????
        while 1:
            if len(self.heap) == 0:
                break
            start = heapq.heappop(self.heap)
            # ????????????????????????????????????
            if self.visited[start[1]] != -1:
                continue
            # ???????visit???????
            self.visited[start[1]] = start[0]
            for i in range(len(self.adj)):
                if self.visited[i] == -1 and self.adj[start[1]][i] != 0:
                    heapq.heappush(self.heap, [self.adj[start[1]][i] + self.visited[start[1]], i])
        # print("start:{} score:{}".format(_start, max(self.visited)))
        return self.visited


def condition(t):
    for i in range(len(_adj)):
        for j in range(len(_adj[i])):
            if _adj[i][j] == "#":
                # ???"#"???????????1???
                if i + 1 < h:
                    adj[w * (i + 1) + j][w * i + j] = t
                if j + 1 < w:
                    adj[w * i + j + 1][w * i + j] = t
            else:
                if i + 1 < h:
                    adj[w * (i + 1) + j][w * i + j] = 1
                if j + 1 < w:
                    adj[w * i + j + 1][w * i + j] = 1
            if i + 1 < h:
                if _adj[i + 1][j] == "#":
                    adj[w * i + j][w * (i + 1) + j] = t
                else:
                    adj[w * i + j][w * (i + 1) + j] = 1
            if j + 1 < w:
                if _adj[i][j + 1] == "#":
                    adj[w * i + j][w * i + j + 1] = t
                else:
                    adj[w * i + j][w * i + j + 1] = 1
    dij = dijkstra(adj=adj)
    return dij.allSearch(start)[goal]


class binarySearch:
    # ??????????
    # ????t??????????????????
    def __init__(self, limit, target):
        self.limit = limit
        self.target = target

    # min(table) <= target <= max(table)???
    def search(self):
        low = 0
        high = self.limit
        # t ???????
        t = int((low + high) / 2)
        out = -1
        # ??????low????high???????
        # low?high????????????????????
        while high >= low:
            # ?????t????????
            _out = condition(t)
            # print("t:{} target:{} limit:{}".format(t, self.target, self.limit))
            if out == self.target:
                break
            out = _out
            if out < self.target:
                low = t + 1
            elif out > self.target:
                high = t - 1
            t = int((low + high) / 2)
        return t

h, w, t = [int(i) for i in input().split()]
_adj = [[0 for i in range(w)] for j in range(h)]
adj = [[0 for i in range(w * h)] for j in range(w * h)]
start = 0
goal = 0
for i in range(h):
    _inpAdj = input()
    for j in range(w):
        _adj[i][j] = _inpAdj[j]
        if _inpAdj[j] == "S":
            start = w * i + j
        if _inpAdj[j] == "G":
            goal = w * i + j
binary = binarySearch(t, t)
print(binary.search())