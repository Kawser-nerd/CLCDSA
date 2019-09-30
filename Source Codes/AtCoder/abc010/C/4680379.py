t_x_a, t_y_a, t_x_b, t_y_b, t, v = map(int, input().split())

n = int(input())

x = []
y = []
for i in range(n):
    _x, _y = map(int, input().split())
    x.append(_x)
    y.append(_y)

is_cheating = False

for i in range(n):
    if ((t_x_a - x[i]) ** 2 + (t_y_a - y[i]) ** 2) ** 0.5 + ((t_x_b - x[i]) ** 2 + (t_y_b - y[i]) ** 2) ** 0.5 <= t * v:
        is_cheating = True
        break

print("YES" if is_cheating else "NO")