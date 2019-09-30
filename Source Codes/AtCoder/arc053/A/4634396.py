H, W = map(int, input().split())

if H == 1 and W == 1:
    ans = 0
elif H == 1:
    ans = W - 1
elif W == 1:
    ans = H - 1
else:
    ans = (H - 1) * W + H * (W - 1)

print(ans)