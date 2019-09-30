x, y = map(int, input().split())

cnt = float('inf')
for first, add_cnt_f in (-1, 1), (1, 0):
    xx = x * first
    for last, add_cnt_l in (-1, 1), (1, 0):
        yy = y * last
        if yy >= xx:
            cnt = min(cnt, add_cnt_f + add_cnt_l + yy - xx)
print(cnt)