x1, y1, x2, y2 = map(int, input().split())
vector = (x2-x1, y2-y1)

x3, y3 = x2 - vector[1], y2-(-vector[0])
x4, y4 = x3 - vector[0], y3-vector[1]

print(" ".join(map(str, [x3,y3,x4,y4])))