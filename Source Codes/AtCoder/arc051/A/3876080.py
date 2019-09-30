X1, Y1, R = map(int, input().split(" "))
X2, Y2, X3, Y3 = map(int, input().split(" "))

min_x, max_x = sorted([X2, X3])
min_y, max_y = sorted([Y2, Y3])

is_red = False
for x, y in [(X1+R, Y1), (X1-R, Y1), (X1, Y1+R), (X1, Y1-R)]:
    if min_x <= x <= max_x and min_y <= y <= max_y:
        continue
    is_red = True
    break

is_blue = False
for x, y in [(X2, Y2), (X2, Y3), (X3, Y2), (X3, Y3)]:
    if (abs(X1-x)**2 + abs(Y1-y)**2)**(1/2) <= R:
        # print((abs(X1-x)**2 + abs(Y1-y)**2)**(1/2), x, y)
        continue
    is_blue = True
    break

print(["NO", "YES"][is_red])
print(["NO", "YES"][is_blue])