def b_tree(N, X, H, Edges):
    # ?????0-based????????????
    x = X - 1
    graph = [[] for _ in [0] * N]
    for a, b in Edges:
        a, b = a - 1, b - 1
        graph[a].append(b)
        graph[b].append(a)

    is_visited = [False] * N
    is_exist_treasure = [True if h == 1 else False for h in H]
    ans = 0

    # ??X??dfs???
    def dfs(v):
        # ??v????????????
        nonlocal ans
        is_visited[v] = True
        need_reach = is_exist_treasure[v]
        for target in graph[v]:
            if is_visited[target]:
                continue
            if dfs(target):
                # ??target???????????????v????????
                ans += 2  # ???????????????????2???
                need_reach = True
        return need_reach

    dfs(x)
    return ans

N, X = [int(i) for i in input().split()]
H = [int(i) for i in input().split()]
Edges = [[int(i) for i in input().split()] for j in range(N - 1)]
print(b_tree(N, X, H, Edges))