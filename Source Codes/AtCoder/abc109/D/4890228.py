H, W = map(int, input().split())

data = [list(map(int, input().split())) for _ in range(H)]

way = []
for h in range(H):
    for w in range(W):
        if h % 2 == 0:
            if data[h][w] % 2 == 1:
                if w < W-1:
                    way.append((h+1, w+1, h+1, w+2))
                    data[h][w+1] += 1
                elif h+1 < H:
                    way.append((h+1, w+1, h+2, w+1))
                    data[h+1][w] += 1
        else:
            w = W - 1 - w
            if data[h][w] % 2 == 1:
                if w > 0:
                    way.append((h+1, w+1, h+1, w))
                    data[h][w-1] += 1
                elif h+1 < H:
                    way.append((h+1, w+1, h+2, w+1))
                    data[h+1][w] += 1

print(len(way))
for a, b, c, d in way:
    print(a, b, c, d)