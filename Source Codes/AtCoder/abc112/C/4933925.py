n = int(input())
xyhs = [list(map(int, input().split())) for _ in range(n)]
ans_cx = 0
ans_cy = 0
ans_h = 0

if n == 1:
    ans_cx, ans_cy, ans_h = xyhs[0]
elif all([xyh[2] == 0 for xyh in xyhs]):
    ans_cx = 0
    ans_cy = 0
    for x, y, h in xyhs:
        ans_cx += x
        ans_cy += y
    ans_cx //= n
    ans_cy //= n
    ans_h = abs(xyhs[0][0] - ans_cx) + abs(xyhs[0][1] - ans_cy)
else:
    for cx in range(101):
        for cy in range(101):
            h_set = set([h + abs(x - cx) + abs(y - cy) for x, y, h in xyhs if h != 0])
            if len(h_set) > 1:
                continue
            h_ = list(h_set)[0]
            if all([max(h_ - abs(x - cx) - abs(y - cy), 0) == h for x, y, h in xyhs]):
                ans_cx = cx
                ans_cy = cy
                ans_h = h_

print(ans_cx, ans_cy, ans_h)