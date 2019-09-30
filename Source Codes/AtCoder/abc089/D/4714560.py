H, W, D = map(int, input().split())
Aij = [list(map(int, input().split())) for _ in range(H)]
Q = int(input())
LRi = [list(map(int, input().split())) for _ in range(Q)]

# ??????????
pos = [0] * (H * W + 1)
for i in range(H):
    for j in range(W):
        pos[Aij[i][j]] = [i, j]

# ????????
mp_sum = [0] * (H * W + 1)
for i in range(D + 1, H * W + 1):
    s = pos[i - D]
    e = pos[i]
    mp_sum[i] = mp_sum[i - D] + abs(e[0] - s[0]) + abs(e[1] - s[1])


for lr in LRi:
    mp = mp_sum[lr[1]] - mp_sum[lr[0]]
    print(mp)