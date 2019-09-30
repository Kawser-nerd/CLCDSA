N, M = map(int, input().split())
items = []
for i in range(M):
    items.append(tuple(map(int, input().split())))

red = [False] * N
box = [1] * N
red[0] = True

for i in range(M):
    x, y = items[i]
    x, y = x - 1, y - 1

    if box[x] and red[x]:
        red[y] = True

    if box[x] == 1 and red[x]:
        red[x] = False

    box[x] -= 1
    box[y] += 1

print(red.count(True))