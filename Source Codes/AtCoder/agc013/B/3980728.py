N, M = map(int, input().split())
Edge = [[] for i in range(N)]
for _ in range(M):
    a, b = map(int, input().split())
    Edge[a-1].append(b-1)
    Edge[b-1].append(a-1)
Used = [False for i in range(N)]
Path = [1, Edge[0][0]+1]
Used[0], Used[Edge[0][0]] = True, True
AFin, BFin = False, False
Anext, Bnext = 0, Edge[0][0]
for node in Edge[0]:
    if not Used[node]:
        Anext = node
        Used[Anext] = True
        break
else: AFin = True
for node in Edge[Bnext]:
    if not Used[node]:
        Bnext = node
        Used[Bnext] = True
        break
else: BFin = True

while not AFin or not BFin:
    if not AFin:
        Path.insert(0, Anext+1)
        for node in Edge[Anext]:
            if not Used[node]:
                Anext = node
                Used[Anext] = True
                break
        else: AFin = True
    if not BFin:
        Path.append(Bnext+1)
        for node in Edge[Bnext]:
            if not Used[node]:
                Bnext = node
                Used[Bnext] = True
                break
        else: BFin = True

print(len(Path))
print(" ".join(map(str, Path)))