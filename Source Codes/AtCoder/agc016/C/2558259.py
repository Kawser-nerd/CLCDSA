def get_1d(H, h):
    ret = [0] * (H + 1)
    for s in range(h):
        for x, i in enumerate(range(s, H, h)):
            ret[i] = -x
    for x, i in enumerate(range(H, 0, -h)):
        ret[i] = x + 1
    return [x1 - x0 for x0, x1 in zip(ret, ret[1:])]


def solve(H, W, h, w):
    if H % h == 0 and W % w == 0:
        return False
    ans = []
    if H % h > 0:
        col = get_1d(H, h)
        ans.extend([x] * W for x in col)
    else:
        row = get_1d(W, w)
        ans.extend([row] * H)
    return ans


H, W, h, w = map(int, input().split())
ans = solve(H, W, h, w)
if ans == False:
    print('No')
else:
    print('Yes')
    for row in ans:
        print(*row)