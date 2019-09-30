from math import sqrt

n = int(input())
points = []
for i in range(n):
    point = list(map(int,input().split()))
    points.append(point)
ans = 0
while not points == []:
    point = points.pop()
    x, y = point
    for other in points:
        x1, y1 = other
        ans = max(ans, sqrt((x - x1)**2 + (y - y1)**2))
print("{:.6f}".format(ans,))