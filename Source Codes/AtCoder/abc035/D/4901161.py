def d_treasure_hunt(N, M, T, A, From_list, To_list, Weight_list):
    # ??: https://atcoder.jp/contests/abc035/submissions/677725
    from numpy import inf
    from scipy.sparse import csr_matrix
    from scipy.sparse.csgraph import dijkstra

    graph = csr_matrix((Weight_list, (From_list, To_list)), shape=(N, N))
    graph_rev = csr_matrix((Weight_list, (To_list, From_list)), shape=(N, N))
    forward, backward = dijkstra(graph, indices=0), dijkstra(graph_rev, indices=0)

    # ???k? ???/?? ????????????forward[k]/backward[k]???
    # ??????????k????????????????????
    return max(a * (T - int(f + b)) for f, b, a in zip(forward, backward, A) if f + b != inf)

N, M, T = [int(i) for i in input().split()]
A = [int(i) for i in input().split()]
From_list, To_list, Weight_list = [], [], []
for _ in range(M):
    a, b, c = map(int, input().split())
    From_list.append(a - 1)
    To_list.append(b - 1)
    Weight_list.append(c)
print(d_treasure_hunt(N, M, T, A, From_list, To_list, Weight_list))