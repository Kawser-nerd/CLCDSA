ADJUSTS = [(0, 1), (1, 0), (0, -1), (-1, 0)]

N, M = map(int, input().split(" "))
B = [list(map(int, input())) for _ in range(N)]

C = [[0 for _ in range(M)] for _ in range(N)]

for this_y in range(1, N-1):
    for this_x in range(1, M-1):
        min_num = 10
        for ad_x, ad_y in ADJUSTS:
            x, y = this_x+ad_x, this_y+ad_y
            min_num = min(min_num, B[y][x])
        # print(min_num)
        for ad_x, ad_y in ADJUSTS:
            x, y = this_x+ad_x, this_y+ad_y
            B[y][x] -= min_num
        C[this_y][this_x] = min_num

for c in C:
    print("".join(map(str, c)))