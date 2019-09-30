import sys

sys.setrecursionlimit(10000)
parents = []
edgecopy = []


def DP(node):
    childsizes = []
    aScores = []
    for child in edges[node]:
        if child == parents[node]:
            continue
        parents[child] = node;
        size,score = DP(child)
        childsizes.append(size)
        aScores.append(size-score)
    totalsize = sum(childsizes)+1
    if len(childsizes)<2:
        return (totalsize,totalsize-1)
    else:
        aScores.sort()
        return (totalsize,totalsize-1-aScores[-1]-aScores[-2])
    

T = int(input())
for case in range(1,T+1):
    N = int(input())
    edges = [[] for i in range(N)]
    for e in range(N-1):
        x,y = (int(x) for x in input().split())
        edges[x-1].append(y-1)
        edges[y-1].append(x-1)
    ans = N
    for root in range(N):
        edgecopy[:] = [edges[x][:] for x in range(N)]
        parents[:] = [-1]*N
        parents[root] = root
        (size,score) = DP(root)
        ans = min(ans,score)
    print("Case #",case,": ",ans,sep = '')
