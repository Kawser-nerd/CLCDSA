import sys

def dfs(edges, start):
    visited = [0]*len(edges)
    visited[start] = 1
    ans, dist = 0, 0
    stack = [(start, 0)]
    pop, append = stack.pop, stack.append

    while stack:
        v, _dist = pop()
        if _dist > dist:
            ans, dist = v, _dist

        for e in edges[v]:
            if visited[e]:
                continue
            visited[e] = 1
            append((e, _dist+1))

    return ans, dist


if __name__ == "__main__":
    N = int(input())
    edges = [[] for _ in [0]*N]
    for (a, b) in (map(int, l.split()) for l in sys.stdin):
        edges[a-1].append(b-1)
        edges[b-1].append(a-1)

    v, _ = dfs(edges, 0)
    print(v+1, dfs(edges, v)[0]+1)