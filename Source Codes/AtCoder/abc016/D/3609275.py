import math


def input_parse():
    return tuple(int(c) for c in input().split())


def sort_linePoint(Ax, Ay, Bx, By):
    if Ax > Bx or (Ax == By and Ay > By):
        tmpx = Ax
        tmpy = Ay
        Ax = Bx
        Ay = By
        Bx = tmpx
        By = tmpy
    return Ax, Ay, Bx, By


Ax, Ay, Bx, By = input_parse()
Ax, Ay, Bx, By = sort_linePoint(Ax, Ay, Bx, By)

Bx_dash = Bx - Ax
By_dash = By - Ay

if By_dash == 0:
    sin_theta = 0
    cos_theta = 1

    Bx_dash_rot = Bx_dash
    By_dash_rot = 0

elif Bx_dash == 0:
    sin_theta = -1
    cos_theta = 0

    Bx_dash_rot = By_dash
    By_dash_rot = 0

else:
    theta = math.atan2(By_dash, Bx_dash)
    sin_theta = math.sin(-theta)
    cos_theta = math.cos(-theta)

    Bx_dash_rot = Bx_dash * cos_theta - By_dash * sin_theta
    By_dash_rot = 0


def transCoordinate(x, y):
    x = x - Ax
    y = y - Ay
    x_rot = x * cos_theta - y * sin_theta
    y_rot = x * sin_theta + y * cos_theta
    return x_rot, y_rot


N, = input_parse()

vertices = []
for i in range(N):
    x, y = input_parse()
    vertices.append(transCoordinate(x, y))

pre_x, pre_y = vertices[-1]

inter_count = 0
for (x, y) in vertices:
    if pre_y * y >= 0:
        pre_x, pre_y = x, y
        continue

    if pre_x == x:
        intersection_x = x
    else:
        intersection_x = (pre_y * x - y * pre_x) / (pre_y - y)

    if 0 <= intersection_x and intersection_x <= Bx_dash_rot:
        inter_count += 1
    pre_x, pre_y = x, y

print(int(inter_count / 2 + 1))