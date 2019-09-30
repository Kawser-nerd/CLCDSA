Ax, Ay, Bx, By = map(int, input().split())
n = int(input())
pos = [list(map(int, input().split())) for _ in range(n)]
pos.append([pos[0][0], pos[0][1]])

# ???????a, b??? = |a||b|sin = ax*by - ay*bx
# ??a0(x0, y0)a1(x1, y1) ?, ??b0(x2, y2), b1(x3, y3)?????
def cross_judge(x0, y0, x1, y1, x2, y2, x3, y3):
    # a0a1 ? a0b0????
    ax = x1 - x0
    ay = y1 - y0
    bx = x2 - x0
    by = y2 - y0
    cross_product0 = ax * by - ay * bx

    # a0a1 ? a0b1????
    ax = x1 - x0
    ay = y1 - y0
    bx = x3 - x0
    by = y3 - y0
    cross_product1 = ax * by - ay * bx

    # b0b1 ? b0a0????
    ax = x3 - x2
    ay = y3 - y2
    bx = x2 - x0
    by = y2 - y0
    cross_product2 = ax * by - ay * bx

    # b0b1 ? b0a1????
    ax = x3 - x2
    ay = y3 - y2
    bx = x2 - x1
    by = y2 - y1
    cross_product3 = ax * by - ay * bx

    if cross_product0 * cross_product1 < 0 and cross_product2 * cross_product3 < 0:
        return True
    else:
        return False


pre_x = pos[0][0]
pre_y = pos[0][1]
count = 0
for i, (x, y) in enumerate(pos):
    if i == 0:
        continue
    if cross_judge(Ax, Ay, Bx, By, pre_x, pre_y, x, y):
        count += 1
    pre_x = x
    pre_y = y

print(count // 2 + 1)