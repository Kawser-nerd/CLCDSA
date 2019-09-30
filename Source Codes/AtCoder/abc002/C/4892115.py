x1, y1, x2, y2, x3, y3 = (int(x) for x in input().split(" "))
answer = abs((x2 - x1) * (y3 - y1) - (y2 - y1) * (x3 - x1)) / 2
print(answer)