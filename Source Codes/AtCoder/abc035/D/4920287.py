import heapq


class PriorityQueue:
    def __init__(self):
        self.__heap = []
        self.__count = 0

    def empty(self) -> bool:
        return self.__count == 0

    def dequeue(self):
        if self.empty():
            raise Exception('empty')
        self.__count -= 1
        return heapq.heappop(self.__heap)

    def enqueue(self, v):
        self.__count += 1
        heapq.heappush(self.__heap, v)

    def __len__(self):
        return self.__count


def dijkstra(graph: list, s: int)->list:
    INF = float('inf')

    d = [INF] * len(graph)
    d[s] = 0

    q = PriorityQueue()
    q.enqueue((d[s], s))

    while not q.empty():
        _, u = q.dequeue()

        for v, c in graph[u]:
            alt = d[u] + c
            if alt < d[v]:
                d[v] = alt
                q.enqueue((d[v], v))

    return d


def treasure_hant(N: int, M: int, T: int, A: list, edges: list)->int:
    forward = [[] for _ in range(N)]
    backward = [[] for _ in range(N)]
    for u, v, c in edges:
        forward[u-1].append((v-1, c))
        backward[v-1].append((u-1, c))

    df = dijkstra(forward, 0)
    db = dijkstra(backward, 0)

    return max((T - df[i] - db[i]) * A[i] for i in range(N))


if __name__ == "__main__":
    M = 0
    N, M, T = map(int, input().split())
    A = [int(s) for s in input().split()]
    edges = [tuple(int(s) for s in input().split()) for _ in range(M)]
    ans = treasure_hant(N, M, T, A, edges)
    print(ans)