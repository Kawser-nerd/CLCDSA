import numpy as np
 
N, M, Q = map(int, input().split())
 
S = np.zeros((N+1, M+1), dtype='float32')
 
for n in range(1, N+1):
    S[n, 1:] = list(map(int, list(input())))
 
# count nodes
N_cum = np.cumsum(np.cumsum(S, axis=0), axis=1) 
# count edges(row)
ER_cum = np.cumsum(np.cumsum(S[:N, :]*S[1:, :], axis=0), axis=1) 
# count edges(col)
EC_cum = np.cumsum(np.cumsum(S[:, :M]*S[:, 1:], axis=0), axis=1) 
 
sol_list = []
 
for _ in range(Q):
    x1, y1, x2, y2 = map(int, input().split())
    # nodes
    N_nodes = N_cum[x2, y2] - N_cum[x1-1, y2] - N_cum[x2, y1-1] + N_cum[x1-1, y1-1]
    # edges(row)
    N_edges1 = ER_cum[x2-1, y2] - ER_cum[x1-1, y2] - ER_cum[x2-1, y1-1] + ER_cum[x1-1, y1-1]
    # edges(col)
    N_edges2 = EC_cum[x2, y2-1] - EC_cum[x1-1, y2-1] - EC_cum[x2, y1-1] + EC_cum[x1-1, y1-1]
    
    sol_list.append(N_nodes - N_edges1 - N_edges2)
 
for q in range(Q):
    print(int(sol_list[q]))