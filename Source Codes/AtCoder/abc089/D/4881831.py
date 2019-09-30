H, W, D = map(int, input().split())
A = [list(map(int, input().split())) for i in range(H)]


Position = {}
for h in range(H):
    for w in range(W):
        Position[A[h][w]] = (h, w)


Cost = [0] * (H * W + 1)
for d in range(D + 1, H * W + 1):
    h, w = Position[d]
    prev_h, prev_w = Position[d - D]
    Cost[d] = abs(h - prev_h) + abs(w - prev_w) + Cost[d - D]


Q = int(input())
for q in range(Q):
    l, r = map(int, input().split())
    print(Cost[r] - Cost[l])