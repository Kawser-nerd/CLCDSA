N = int(input())
xyh = [tuple(map(int, input().split())) for _ in range(N)]

for cx in range(100 + 1):
    for cy in range(100 + 1):
        # ????????????
        H = -1
        for x, y, h in xyh:
            if h > 0:
                t = h + abs(x - cx) + abs(y - cy)
                if H == -1:
                    H = t
                else:
                    if H != t:
                        # ???????????????????H?????
                        break
        else:
            for x, y, h in xyh:
                if h != max(H - abs(x - cx) - abs(y - cy), 0):
                    break
            else:
                if H >= 1:
                    print(cx, cy, H)
                    exit()