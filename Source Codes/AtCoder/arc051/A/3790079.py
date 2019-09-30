x1, y1, r = map(int, input().split())
x2, y2, x3, y3 = map(int, input().split())

red = "NO"
blue = "NO"

if x2 > x1 - r or x1+r > x3 or  y2 > y1 - r or y1 + r > y3:
    red = "YES"

for x in [x2, x3]:
    for y in [y2, y3]:
        if (x1-x)**2 + (y1-y)**2 > r**2:
            blue = "YES"
print(red)
print(blue)