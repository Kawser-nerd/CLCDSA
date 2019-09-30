def b_trees(N, Color):
    if len(set(Color)) == 1:
        return -1  # ?????????????????????

    color_cycle = Color + Color  # ??????????
    color_continuity = 1
    tmp_continuity = 1
    # ???????????????????
    for k in range(N * 2):
        if color_cycle[k] == color_cycle[k - 1]:
            tmp_continuity += 1
        else:
            color_continuity = max(color_continuity, tmp_continuity)
            tmp_continuity = 1
    ans = ((color_continuity - 1) // 2) + 1
    return ans

N = int(input())
Color = [int(input()) for _ in [0] * N]
print(b_trees(N, Color))