import sys

x1, y1, x2, y2 = map(int, input().split())
x, y = x2 - x1, y2 - y1

print(x2 - y, y2 + x, x1 - y, y1 + x)