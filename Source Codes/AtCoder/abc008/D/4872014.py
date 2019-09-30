def calc(i, j, k, l):
    if (i, j, k, l) in memo:
        return memo[(i, j, k, l)]
    res = 0
    for X, Y in M:
        # ???????????????????????
        if i < X <= k and j < Y <= l:
            # ??????????
            tmp = (k-i) + (l-j) - 1
            # ????????????????????
            tmp += calc(i, j, X-1, Y-1)
            tmp += calc(X, j, k, Y-1)
            tmp += calc(i, Y, X-1, l)
            tmp += calc(X, Y, k, l)
            res = max(res, tmp)
    memo[(i, j, k, l)] = res
    return res


W, H = map(int, input().split(' '))
N = int(input())
M = [tuple(map(int, input().split(' '))) for _ in range(N)]
memo = {}
print(calc(0, 0, W, H))