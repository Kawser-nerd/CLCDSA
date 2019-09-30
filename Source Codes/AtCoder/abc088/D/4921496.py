from collections import deque
H, W = map(int, input().split())
G = [list(input()) for i in range(H)]


first_black = sum([row.count('#') for row in G])
que = deque([(0, 0)])
dist = [[-1] * W for i in range(H)]
dist[0][0] = 0
direction = [(0, 1), (0, -1), (1, 0), (-1, 0)]

while que:
    nh, nw = que.pop()
    for dh, dw in direction:
        if not ((0 <= nh + dh < H) & (0 <= nw + dw < W)):
            continue
        if G[nh + dh][nw + dw] == '#':
            continue
        if dist[nh + dh][nw + dw] > 0:
            continue

        dist[nh + dh][nw + dw] = dist[nh][nw] + 1
        que.appendleft((nh + dh, nw + dw))


if dist[-1][-1] != -1:
    print(H * W - dist[-1][-1] - first_black - 1)
else:
    print(-1)