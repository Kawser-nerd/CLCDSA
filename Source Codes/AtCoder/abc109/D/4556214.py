H, W = map(int, input().split())

Ai = []
for _ in range(H):
    a = list(map(int, input().split()))
    Ai.append(a)

operations = []

# 0 <= x,y < W or H
def get_text(y1, x1, y2, x2):
    return str(y1 + 1) + " " + str(x1 + 1) + " " + str(y2 + 1) + " " + str(x2 + 1)

for y in range(H):
    if y % 2 == 0:
        for x in range(W):
            if Ai[y][x] % 2 == 0:
                continue
            if x == W - 1:
                if y < H - 1:
                    Ai[y][x] -= 1
                    Ai[y + 1][x] += 1
                    operations.append(get_text(y, x, y + 1, x))
            else:
                Ai[y][x] -= 1
                Ai[y][x + 1] += 1
                operations.append(get_text(y, x, y, x + 1))
    else:
        for x in range(W - 1, -1, -1):
            if Ai[y][x] % 2 == 0:
                continue
            if x == 0:
                if y < H - 1:
                    Ai[y][x] -= 1
                    Ai[y + 1][x] += 1
                    operations.append(get_text(y, x, y + 1, x))
            else:
                Ai[y][x] -= 1
                Ai[y][x - 1] += 1
                operations.append(get_text(y, x, y, x - 1))

print(len(operations))
for o in operations:
    print(o)