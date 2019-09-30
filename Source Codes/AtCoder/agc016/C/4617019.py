H, W, h, w = map(int, input().split())
p = 1000
if H % h > 0 or W % w > 0:
    print("Yes")
    a = [ [p] * W for i in range(H) ]
    for i in range(h-1, H, h):
        for j in range(w-1, W, w):
            a[i][j] = - p * (h * w - 1) - 1
    for i in range(H):
        print(' '.join(map(str, a[i])))
else:
    print("No")