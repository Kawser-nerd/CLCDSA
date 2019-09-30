from collections import deque

# ??????????
def addEdge(adjL, vFr, vTo, cap):
    adjL[vFr].append([vTo, cap, len(adjL[vTo])])
    adjL[vTo].append([vFr, 0, len(adjL[vFr]) - 1]) # ??


# Dinic????????????
def Dinic(adjL, vSt, vEn):

    # ???????????BFS????
    def BFS(vSt):
        dist[vSt] = 0
        Q = deque([vSt])
        while Q:
            vNow = Q.popleft()

            for i, (v2, cap, iRev) in enumerate(adjL[vNow]):
                if dist[v2] == -1 and cap > 0:
                    # ?????????????????????????
                    dist[v2] = dist[vNow] + 1
                    Q.append(v2)


    # ?????????????????????????DFS?????
    def DFS(vNow, vEn, fNow):
        if vNow == vEn:
            # ???????????????????
            return fNow

        # ???????????????
        iSt = iNext[vNow]
        for i, (v2, cap, iRev) in enumerate(adjL[vNow][iSt:], iSt):
            if dist[vNow] < dist[v2] and cap > 0:
                # ???????????????????????????????????
                df = DFS(v2, vEn, min(fNow, cap))
                if df > 0:
                    # ??????????????????????????
                    adjL[vNow][i][1] -= df
                    adjL[v2][iRev][1] += df
                    return df

            iNext[vNow] += 1

        # ??????????????????????
        return 0


    numV = len(adjL)
    MaximumFlow = 0
    while True:
        # ???????????BFS????
        dist = [-1] * numV
        BFS(vSt)
        if dist[vEn] == -1:
            # ???????????????????????????
            return MaximumFlow

        iNext = [0] * numV
        while True:
            # ?????????????????????????DFS?????
            df = DFS(vSt, vEn, float('inf'))

            if df == 0:
                # ???????????????????
                break

            # ????????
            MaximumFlow += df


N = int(input())
As = list(map(int, input().split()))

adjList = [[] for v in range(N + 2)]
for i, A in enumerate(As, 1):
    if A <= 0:
        addEdge(adjList, 0, i, -A)
    else:
        addEdge(adjList, i, N + 1, A)

for i in range(1, N + 1):
    for j in range(2 * i, N + 1, i):
        addEdge(adjList, i, j, float('inf'))

# Dinic????????????
mf = Dinic(adjList, 0, N + 1)
print(sum([A for A in As if A > 0]) - mf)