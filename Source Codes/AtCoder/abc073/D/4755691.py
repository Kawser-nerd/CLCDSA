import heapq


def construct_graph(A, B, C):
    M = len(A)
    graph = {}
    for i in range(M):
        a = A[i]
        b = B[i]
        c = C[i]
        if a not in graph:
            graph[a] = {}
        if b not in graph:
            graph[b] = {}
        graph[a][b] = c
        graph[b][a] = c
    return graph


def dijkstra(graph, s, t):
    q = [(0, s)]
    fix = set()
    d = {}
    d[s] = 0
    while len(q) > 0:
        cur_d, n = heapq.heappop(q)
        if n in fix:
            continue
        fix.add(n)
        if n == t:
            break
        for v in graph[n]:
            if v in fix:
                continue
            c = graph[n][v]
            if v not in d or d[v] > d[n] + c:
                d[v] = d[n] + c
            heapq.heappush(q, (d[v], v))
    return d[t]


def dijkstra_all(graph, nodes):
    d = {}
    for n in nodes:
        d[n] = {}
        for n2 in nodes:
            if n == n2: 
                continue
            if n2 not in d:
                d[n2] = {}
            d[n][n2] = dijkstra(graph, n, n2)
            d[n2][n] = d[n][n2]
    return d


def tsp_dist(graph):
    graph[-1] = {}
    for n in graph:
        if n == -1: continue
        graph[-1][n] = 0
    return tsp(graph, set(), -1)


def tsp(graph, visited, s):
    if len(visited) + 1 == len(graph):
        return 0
    min_d = None
    for n in graph[s]:
        if n in visited: continue
        c = graph[s][n]
        dist = tsp(graph, visited | set([s]), n) + c
        if min_d is None or min_d > dist:
            min_d = dist
    return min_d


def solve(r, A, B, C):
    graph = construct_graph(A, B, C)
    d = dijkstra_all(graph, r)
    minimum_dist = tsp_dist(d)
    return minimum_dist


def main():
    N, M, R = list(map(int, input().split(' ')))
    r = list(map(int, input().split(' ')))
    A = []
    B = []
    C = []
    for i in range(M):
        a, b, c = list(map(int, input().split(' ')))
        A.append(a)
        B.append(b)
        C.append(c)
    print(solve(r, A, B, C))

if __name__ == '__main__':
    main()