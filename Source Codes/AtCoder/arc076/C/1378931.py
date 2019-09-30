R, C, N = map(int, input().split())

points = []

def dist(x, y):
    if x == 0:
        return R * 2 + C + (C - y)
    if x == R:
        return R + y
    if y == 0:
        return x
    if y == C:
        return R + C + (R - x)

for i in range(N):
    x1, y1, x2, y2 = map(int, input().split())
    if ((x1 == 0 or x1 == R) or (y1 == 0 or y1 == C)) and ((x2 == 0 or x2 == R) or (y2 == 0 or y2 == C)):
        points.append((i + 1, dist(x1, y1)))
        points.append((i + 1, dist(x2, y2)))
points.sort(key=lambda p: p[1])
l = []
for point in points:
    if len(l) == 0:
        l.append(point[0])
        continue
    if point[0] == l[-1]:
        l.pop()
    else:
        l.append(point[0])
if len(l) == 0:
    print("YES")
else:
    print("NO")