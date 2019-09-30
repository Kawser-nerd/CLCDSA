W, H, N = map(int, input().split())
x_left = 0
x_right = W
y_bottom = 0
y_top = H
for _ in range(N):
    x, y, a = map(int, input().split())
    if a == 1:
        x_left = max(x_left, x)
    elif a == 2:
        x_right = min(x_right, x)
    elif a == 3:
        y_bottom = max(y_bottom, y)
    elif a == 4:
        y_top = min(y_top, y)
print(max(0, x_right - x_left) * max(0, y_top - y_bottom))