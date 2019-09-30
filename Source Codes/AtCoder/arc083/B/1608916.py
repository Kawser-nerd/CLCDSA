import numpy as np
import scipy.sparse.csgraph as csg

if __name__ == '__main__':
    N = int(input())
    A = [list(map(int, input().split())) for i in range(N)]

    G = np.asarray(A, dtype=np.uint32)
    G2 = csg.floyd_warshall(G, directed=False)
    # print(G)
    # print(G2)
    # print(G == G2)
    if np.any(G != G2):
        print(-1)
        exit()
    ans = 0
    G[G == 0] = 1
    for i in range(N):
        for j in range(i + 1, N):
            n = np.min(G[i] + G[j])
            if n > G[i, j]:
                ans += G[i, j]

    print(ans)