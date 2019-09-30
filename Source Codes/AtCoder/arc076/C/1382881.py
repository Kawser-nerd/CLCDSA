def put(i, x, y):
    if x == 0:
        on_top.append((y, i))
    elif x == r:
        on_bottom.append((y, i))
    elif y == 0:
        on_left.append((x, i))
    else:
        on_right.append((x, i))


on_top, on_bottom, on_left, on_right = [], [], [], []

r, c, n = map(int, input().split())
for i in range(n):
    x1, y1, x2, y2 = map(int, input().split())
    if 0 < x1 < r and 0 < y1 < c:
        continue
    if 0 < x2 < r and 0 < y2 < c:
        continue
    put(i, x1, y1)
    put(i, x2, y2)
on_top.sort()
on_bottom.sort(reverse=True)
on_left.sort(reverse=True)
on_right.sort()
stack = []
for on_edge in [on_top, on_right, on_bottom, on_left]:
    for p, i in on_edge:
        if stack and stack[-1] == i:
            stack.pop()
        else:
            stack.append(i)

print('NO' if stack else 'YES')