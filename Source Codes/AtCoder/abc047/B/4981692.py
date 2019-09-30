W, H, N = map(int, input().split())
w, h = 0, 0

for _ in range(N):
    x, y, a = map(int, input().split())
    if a == 1:
        # ????(x?)????
        w = max(w, x)
    elif a == 2:
        # ????(x?)???
        W = min(W, x)
    elif a == 3:
        # ????(y?)????
        h = max(h, y)
    else:
        # ????(y?)???
        H = min(H, y)

if W < w or H < h:
    print(0)
else:
    print((W-w)*(H-h))