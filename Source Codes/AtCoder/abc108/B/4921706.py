x1, y1, x2, y2 = map(int, input().split())

d = (-y2+y1, x2-x1)

print(x2+d[0], y2+d[1], x1+d[0], y1+d[1])