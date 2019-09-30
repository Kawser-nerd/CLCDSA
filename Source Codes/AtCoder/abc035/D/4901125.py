def d_treasure_hunt(N, M, T, A, From_list, To_list, Weight_list):
    from numpy import inf
    from scipy.sparse import csr_matrix
    from scipy.sparse.csgraph import dijkstra

    graph = csr_matrix((Weight_list, (From_list, To_list)), shape=(N, N))
    graph_rev = csr_matrix((Weight_list, (To_list, From_list)), shape=(N, N))
    forward, backward = dijkstra(graph, indices=0), dijkstra(graph_rev, indices=0)

    # ???k? ???/?? ????????????forward[k]/backward[k]???
    # ??????????k????????????????????
    return max(A[i] * (T - int(forward[i] + backward[i])) for i in range(N) if forward[i] != inf and backward[i] != inf)

N, M, T = [int(i) for i in input().split()]
A = [int(i) for i in input().split()]
From_list, To_list, Weight_list = [], [], []
for _ in range(M):
    a, b, c = map(int, input().split())
    From_list.append(a - 1)
    To_list.append(b - 1)
    Weight_list.append(c)
print(d_treasure_hunt(N, M, T, A, From_list, To_list, Weight_list))