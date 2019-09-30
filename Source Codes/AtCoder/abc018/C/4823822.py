# encoding: utf-8
import sys
input = sys.stdin.readline
inf = 10 ** 18

R, C, K = map(int, input().split())
s = [list(input()) for _ in range(R)]

# how many 'o' around
hmat = [[0] * C for _ in range(R)]
# vmat = [[0] * R for _ in range(C)]
for x in range(C):
    sum_tmp = 0
    # ->
    for y in range(R):
        if s[y][x] == 'o':
            if sum_tmp == 0: t = y
            sum_tmp += 1
            dy = (sum_tmp - 1) // 2
            hmat[t + dy][x] = 1 + dy
        else:
            sum_tmp = 0
    # <-
    sum_tmp = 0
    for yi in range(R):
        y = R - 1 - yi
        if s[y][x] == 'o':
            if sum_tmp == 0: b = y
            sum_tmp += 1
            dy = (sum_tmp - 1) // 2
            hmat[b - dy][x] = 1 + dy
        else:
            sum_tmp = 0

### probably correct above ###

# for hrow in hmat: print("#", hrow)

ans = 0
for yi, hrow in enumerate(hmat[(K - 1):(R - K + 1)]):
    imos = [0] * C
    y = yi + K - 1
    # record
    for x in range(C):
        hxy = hmat[y][x]
        if hxy < K:
            loss = K - 1 - hxy
            imos[max(0, x - loss)] += 1
            imos[min(C - 1, x + loss + 1)] -= 1
    # simulate
    tmp = 0
    dmg = [0] * C
    for i, imosi in enumerate(imos):
        tmp += imosi
        dmg[i] = tmp
    # print("#", dmg)
    ans += dmg[(K - 1):(C - K + 1)].count(0)
    
# for alivei in alive: print("#", alivei)
print(ans)