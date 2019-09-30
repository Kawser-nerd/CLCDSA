from queue import Queue


def distances(tree: list, treeSize: int, root: int)->list:
    dists = [0] * treeSize

    q = Queue()
    q.put((root, -1, 0))

    while not q.empty():
        v, prev, d2v = q.get()

        dists[v] = d2v
        for u, dv2u in tree[v]:
            if prev == u:
                continue
            q.put((u, v, d2v + dv2u))

    return dists


def transit_tree_path(
        N: int, edges: list, Q: int, K: int, queries: list)->list:
    tree = [[] for _ in range(N)]
    for u, v, c in edges:
        tree[u-1].append((v-1, c))
        tree[v-1].append((u-1, c))

    d = distances(tree, N, K-1)

    return [d[x-1]+d[y-1] for x, y in queries]


if __name__ == "__main__":
    N = int(input())
    edges = [tuple(map(int, input().split())) for _ in range(N-1)]
    Q = 0
    Q, K = map(int, input().split())
    queries = [tuple(map(int, input().split())) for _ in range(Q)]

    ans = transit_tree_path(N, edges, Q, K, queries)
    for a in ans:
        print(a)