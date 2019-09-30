N, M = map(int, input().split())
inputs = [list(map(int, list(input()))) for _ in range(N)]

vectors = [[1, 1], [2, 0], [1, -1], [0, 0]] # y, x ??
ans = [[0 for _ in range(M)] for _ in range(N)]
for y in range(N):
    for x in range(M):
        if inputs[y][x] == 0:
            continue
        ans[y+1][x] = inputs[y][x]
        for vector in vectors:
            inputs[y+vector[0]][x+vector[1]] -= inputs[y][x]

for item in ans:
    print(''.join(map(str, item)))