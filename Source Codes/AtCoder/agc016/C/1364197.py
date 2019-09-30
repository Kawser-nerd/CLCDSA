H, W, h, w = map(int, input().split())

def solve(H, W, h, w):
    if (W % w == 0 and H % h == 0):
        return False, []
    if (W % w == 0):
        return True, solve_vertical(H, W, h, w)
    return True, solve_horizontal(H, W, h, w)

def solve_horizontal(H, W, h, w):
    return [solve_horizontal_core(W, w)] * H

def solve_horizontal_core(W, w):
    m, r = divmod(W, w)
    row = [0] * W
    row[0] = m + 1
    row[w - 1] = - m - 2
    for i in range(w, W):
        row[i] = row[i - w]
    return row

def solve_vertical(H, W, h, w):
    col = solve_horizontal_core(H, h)
    m = []
    for c in col:
        m.append([c] * W)
    return m

yesno, mat = solve(H, W, h, w)
if yesno:
    print('Yes')
    for row in mat:
        print(*row)
else:
    print('No')