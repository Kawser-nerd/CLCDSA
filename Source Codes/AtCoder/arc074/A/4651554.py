def make_harf(H, W):
    h = H // 2
    small = W * h
    large = W * (H - h)
    w = W // 2
    small2 = w * H
    large2 = (W - w) * H
    if large - small <= large2 - small2:
        return large, small
    else:
        return large2, small2


H, W = map(int, input().split())
ans = float('inf')
for h in range(1, H):
    tmp = [h * W]
    for item in make_harf(H - h, W):
        tmp.append(item)
    ans = min(max(tmp) - min(tmp), ans)
for w in range(1, W):
    tmp = [H * w]
    for item in make_harf(H, W - w):
        tmp.append(item)
    ans = min(max(tmp) - min(tmp), ans)
print(ans)