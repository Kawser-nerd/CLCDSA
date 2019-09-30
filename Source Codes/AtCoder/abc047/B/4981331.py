W, H, N = map(int, input().split())
cells = [[0 for _ in range(W)] for _ in range(H)]
lists = [list(map(int, input().split())) for _ in range(N)]

for ls in lists:
    x, y, a = ls[0], ls[1], ls[2]
    if a == 1:
        # xi ?????????
        for h in range(H):
            for w in range(x):
                cells[h][w] = 1
    elif a == 2:
        # xi ?????????
        for h in range(H):
            for w in range(x, W):
                cells[h][w] = 1
    elif a == 3:
        # yi ?????????
        for h in range(H-y, H):
            for w in range(W):
                cells[h][w] = 1
    else:
        # yi ?????????
        for h in range(H-y):
            for w in range(W):
                cells[h][w] = 1

count = 0
for rows in cells:
    count += rows.count(0)

print(count)