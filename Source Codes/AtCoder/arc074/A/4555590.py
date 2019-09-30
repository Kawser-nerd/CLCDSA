H, W = map(int, input().split())

diff = float("inf")

for h in range(1, H):
    sa = h * W
    nw = W // 2
    sb = (H - h) * nw
    sc = (H - h) * (W - nw)
    diff = min(diff, max(sa, sb, sc) - min(sa, sb, sc))

    nh = (H - h) // 2
    sb = nh * W
    sc = (H - h - nh) * W
    diff = min(diff, max(sa, sb, sc) - min(sa, sb, sc))

for w in range(1, W):
    sa = w * H
    nh = H // 2
    sb = (W - w) * nh
    sc = (W - w) * (H - nh)
    diff = min(diff, max(sa, sb, sc) - min(sa, sb, sc))

    nw = (W - w) // 2
    sb = nw * H
    sc = (W - w - nw) * H
    diff = min(diff, max(sa, sb, sc) - min(sa, sb, sc))

print(diff)