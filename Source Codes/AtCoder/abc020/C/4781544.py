# encoding: utf-8
import sys
input = sys.stdin.readline
inf = 10 ** 18

import heapq

H, W, T = map(int, input().split())
s = [list(input()) for _ in range(H)]

for y in range(H):
    for x in range(W):
        if s[y][x] == 'S': sx, sy = x, y
        elif s[y][x] == 'G': gx, gy = x, y

tblr = ([(0, -1), (0, 1), (-1, 0), (1, 0)])
        
l = 1
r = T
while True:
    m = (l + r + 1) // 2
    # print("#", l, r)
    if l >= r: break
    #
    d = [[inf] * W for _ in range(H)]
    d[sy][sx] = 0
    prev = [[None] * W for _ in range(H)]
    q = []
    heapq.heappush(q, (0, sx, sy))
    while len(q) > 0:
        dur, x, y = heapq.heappop(q)
        # print("##", dur, x, y)
        if dur > d[gy][gx]: continue
        if dur > T: continue
        for i, (dx, dy) in enumerate(tblr):
            if prev[y][x] == i: continue
            if x + dx < 0 or W <= x + dx: continue
            if y + dy < 0 or H <= y + dy: continue
            #
            if s[y + dy][x + dx] == '#': dur_tmp = dur + m
            else: dur_tmp = dur + 1
            if dur_tmp < d[y + dy][x + dx]:
                d[y + dy][x + dx] = dur_tmp
                prev[y + dy][x + dx] = 2 * (i // 2) + (1 - i % 2)
                heapq.heappush(q, (dur_tmp, x + dx, y + dy))
    #
    if d[gy][gx] > T: r = m - 1
    else: l = m

print(m)