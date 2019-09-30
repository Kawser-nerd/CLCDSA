from collections import deque

# ??????????
def addEdge(adjL, vFr, vTo, cap):
    adjL[vFr].append([vTo, cap, len(adjL[vTo])])
    adjL[vTo].append([vFr, 0, len(adjL[vFr]) - 1]) # ??


# Edmonds-Karp????????????
def Edmonds_Karp(adjL, vSt, vEn):

    # ?????????????????????????BFS?????
    def BFS(vSt, vEn):
        prev = [-1] * numV
        prev[vSt] = None
        iE = [-1] * numV
        df = 0
        Q = deque([(vSt, float('inf'))])
        while Q:
            vNow, fNow = Q.popleft()
            if vNow == vEn:
                # ????????????????
                df = fNow
                break

            for i, (v2, cap, iRev) in enumerate(adjL[vNow]):
                if prev[v2] == -1 and cap > 0:
                    # ?????????????????????????
                    prev[v2] = vNow
                    iE[v2] = (i, iRev)
                    Q.append((v2, min(fNow, cap)))

        if df > 0:
            # ??????????????????????????
            vNow = vEn
            while vNow != vSt:
                v0 = prev[vNow]
                e, iRev = iE[vNow]
                adjL[v0][e][1] -= df
                adjL[vNow][iRev][1] += df
                vNow = v0

        # ??????????
        return df


    numV = len(adjL)
    MaximumFlow = 0
    while True:
        # ?????????????????????????BFS?????
        df = BFS(vSt, vEn)

        if df == 0:
            # ??????????????????????
            return MaximumFlow

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

# Edmonds-Karp????????????
mf = Edmonds_Karp(adjList, 0, N + 1)
print(sum([A for A in As if A > 0]) - mf)