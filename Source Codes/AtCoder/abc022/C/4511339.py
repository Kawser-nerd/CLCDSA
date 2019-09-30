from scipy.sparse.csgraph import floyd_warshall as wf

V, M = map(int, input().split())
A = [[int(i) for i in input().split()] for i in range(M)]
INF = float('inf')

d = [[INF] * V for i in range(V)]
for i in range(V):
    d[i][i] = 0
for i, j, k in A:
    if i != 1 and j != 1:
        d[i - 1][j - 1] = k
        d[j - 1][i - 1] = k
#1?????????????????????????

d = wf(d)
                    
A2 = [A[i] for i in range(M) if A[i][0] == 1]
        
ans = INF
for i in A2:
    for j in A2:
        if i != j and d[i[1] - 1][j[1] - 1] != INF:
            tmp = i[2] + j[2] + d[i[1] - 1][j[1] - 1]
            ans = min(ans, tmp)
            #1?????????????????????????????
        
if ans == INF:
    print(-1)
else:
    print(int(ans))