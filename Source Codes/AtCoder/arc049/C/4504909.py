from collections import deque

def bfs(edges, r_edges, disable=None):
    disable = disable or set()
    colored = [0]*len(edges)

    for i in range(len(edges)):
        if r_edges[i] or i in disable:
            continue
        colored[i] = 1
        dq = deque([i])
        while dq:
            v = dq.popleft()
            for dest in edges[v]:
                if (not colored[dest]) and (dest not in disable) and all(colored[d] for d in r_edges[dest]):
                    colored[dest] = 1
                    dq.append(dest)

    return colored


if __name__ == "__main__":
    import sys
    from itertools import product
    N = int(input())
    edges, r_edges = [[] for _ in [0]*N], [[] for _ in [0]*N]

    A = int(input())
    for x, y in (map(int, sys.stdin.readline().split()) for _ in [0]*A):
        r_edges[x-1].append(y-1)
        edges[y-1].append(x-1)

    B = int(input())
    queries = [tuple(map(lambda x:int(x)-1, l.split())) for l in sys.stdin]
    ans = 0

    if B:
        for a in product((0, 1), repeat=B):
            added, r_added = [0]*N, [0]*N
            disable = set()

            for t, (q1, q2) in zip(a, queries):
                if t == 0:
                    disable.add(q1)
                else:
                    edges[q1].append(q2)
                    r_edges[q2].append(q1)
                    added[q1] += 1
                    r_added[q2] += 1

            colored = bfs(edges, r_edges, disable)
            ans = max(ans, sum(colored))

            for i in range(N):
                for _ in [0]*added[i]:
                    edges[i].pop()
                for _ in [0]*r_added[i]:
                    r_edges[i].pop()
    else:
        ans = sum(bfs(edges, r_edges))

    print(ans)