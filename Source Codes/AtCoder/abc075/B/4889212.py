import sys; sys.setrecursionlimit(50000)
input = sys.stdin.readline

H, W = map(int, input().split())
grid = [list(input().replace("\n","")) for _ in range(H)]
dir4 = ((0, 1), (0, -1), (1, 0), (-1, 0))
dir8 = ((0, 1), (0, -1), (1, 0), (-1, 0), (-1, -1), (1, -1), (-1, 1), (1, 1))

for i in range(H):
    for j in range(W):
        if grid[i][j] != ".": continue
        cnt = 0
        for d in dir8:
            nx = i + d[0]
            ny = j + d[1]
            if not (0 <= nx < H): continue
            if not (0 <= ny < W): continue
            if grid[nx][ny] == "#": cnt += 1
        grid[i][j] = str(cnt)
    print(*grid[i], sep="")