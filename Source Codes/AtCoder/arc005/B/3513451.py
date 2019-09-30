def b_card(X, Y, W, C):
    h, w = Y - 1, X - 1
    if 'R' in W:
        dw = 1
    elif 'L' in W:
        dw = -1
    else:
        dw = 0

    if 'U' in W:
        dh = -1
    elif 'D' in W:
        dh = 1
    else:
        dh = 0

    ans = ''
    for k in range(4):
        ans += C[h][w]

        is_changed = False
        nh, nw = h + dh, w + dw
        move_tmp = ''
        if not (0 <= nh < 9):
            is_changed = True
            dh *= -1
        if not (0 <= nw < 9):
            is_changed = True
            dw *= -1
        if is_changed:
            nh, nw = h + dh, w + dw
        h, w = nh, nw
    return ans

X, Y, W = [int(i) if i.isdigit() else i for i in input().split()]
C = [input() for _ in range(9)]
print(b_card(X, Y, W, C))