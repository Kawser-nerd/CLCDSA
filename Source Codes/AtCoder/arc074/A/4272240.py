H,W = map(int,input().split())
res = 10**100

for (h, w) in [(H, W), (W, H)]:
    for i in range(1, h):
        k, l = [], []
        k.append(w * i)
        k.append(w * ((h - i) // 2))
        k.append(w * ((h - i) - (h - i) // 2))
        l.append(w * i)
        l.append((h - i) * (w // 2))
        l.append((h - i) * (w - w // 2))
        # print(k, l, w, h - i)
        res = min(res, max(k) - min(k))
        res = min(res, max(l) - min(l))

print(res)