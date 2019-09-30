# coding: utf-8

W, H = map(int, input().rstrip().split())
n = int(input())
ML = [list(map(int, input().rstrip().split())) for _ in range(n)]

def comp(ml, len):
    rml = [[0, 0]]
    for m in ml:
        f, t = rml[-1]
        rml[-1][1] = m - 1
        rml.append([t + 1, m])
    else:
        if m != len:
            rml[-1][1] = len
        rml.append([0, 0])
    return(rml)

xs, ys = zip(*ML)
xs = sorted(xs)
ys = sorted(ys)
w, h = len(xs), len(ys)
cx = comp(xs, W)
cy = comp(ys, H)
ml = [(xs.index(x) + 1, ys.index(y) + 1) for x, y in ML]
dp = [[[[0 for d in range(len(cy))] for r in range(len(cx))] \
           for u in range(len(cy))] for l in range(len(cx))]
for hw in range(2, h + w + 1):
    for wide in range(1, hw):
        for l in range(1, w - wide + 2):
            high = hw - wide
            for u in range(1, h - high + 2):
                r = l + wide - 1
                d = u + high - 1
                g = 0
                for x, y in ml:
                    if l <= x <= r and u <= y <= d:
                        g_ = cx[r][1] - cx[l][0] + 1 + cy[d][1] - cy[u][0] + \
                            dp[l][u][x - 1][y - 1] + \
                            dp[l][y + 1][x - 1][d] + \
                            dp[x + 1][u][r][y - 1] + \
                            dp[x + 1][y + 1][r][d]
                        g = max(g, g_)
                dp[l][u][r][d] = g
print(dp[1][1][w][h])