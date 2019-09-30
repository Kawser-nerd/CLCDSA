w, h, n = map(int, input().split())
w0, h0 = 0, 0
for _ in range(n):
    x, y, a = map(int, input().split())
    if a == 1:
        w0 = max(x, w0)
    elif a == 2:
        w = min(x, w)
    elif a == 3:
        h0 = max(y, h0)
    elif a == 4:
        h = min(y, h)
if w <= w0:
    ans = 0
elif h <= h0:
    ans = 0
else:
    ans = abs(w-w0) * abs(h-h0)
print(ans)