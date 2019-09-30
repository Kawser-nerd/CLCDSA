H, W = map(int, input().split())
A = [list(input()) for h in range(H)]

currentNode = [0, 0]
visited = [["." for w in range(W)] for h in range(H)]
search = [(0, 1), (1, 0)]

while currentNode != [H-1, W-1]:
    visited[currentNode[0]][currentNode[1]] = "#"
    tovisit = []
    for s in search:
        nexth, nextw = currentNode[0] + s[0], currentNode[1] + s[1]
        if 0 <= nexth <= H-1 and 0 <= nextw <= W-1:
            if A[nexth][nextw] == "#" and visited[nexth][nextw] == ".":
                tovisit.append([nexth, nextw])
    if len(tovisit) == 1:
        currentNode = tovisit[0]
    else:
        print("Impossible")
        break
else:
    visited[currentNode[0]][currentNode[1]] = "#"
    flag = True
    for h in range(H):
        for w in range(W):
            if A[h][w] != visited[h][w]:
                flag = False
                break
        if not flag:
            print("Impossible")
            break
    else: print("Possible")