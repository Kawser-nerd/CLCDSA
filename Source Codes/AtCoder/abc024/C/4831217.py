n, d, k = map(int, input().split()) # n????k??????s??????
rst = [list(map(int, input().split())) for _ in range(d)]
dd = [list(map(int, input().split())) for _ in range(k)]
# greedy search
for dpt, dst in dd:
    min_cur, max_cur = dpt, dpt #??????????
    for i, (s, e) in enumerate(rst):
        # ???????????continue
        if not (min_cur <= s <= max_cur or min_cur <= e <= max_cur or s <= min_cur <= e or s <= max_cur <= e):
            continue
        else:
            if min_cur > s:
                min_cur = s
            if max_cur < e:
                max_cur = e
            if min_cur <= dst <= max_cur:
                print(i + 1)
                break