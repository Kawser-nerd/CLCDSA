Ax, Ay, Bx, By = map(int, input().split())
N = int(input())
num = 0


def calc(x0, y0, x1, y1, x2, y2, x3, y3):
    P0 = (x0 - x1) * (y2 - y0) + (y0 - y1) * (x0 - x2)
    Q0 = (x0 - x1) * (y3 - y0) + (y0 - y1) * (x0 - x3)

    P1 = (x2 - x3) * (y0 - y2) + (y2 - y3) * (x2 - x0)
    Q1 = (x2 - x3) * (y1 - y2) + (y2 - y3) * (x2 - x1)

    return P0 * Q0 < 0 and P1 * Q1 < 0


num = 0
preX0, preY0 = map(int, input().split())
preX, preY = preX0, preY0
for i in range(N - 1):
    x, y = map(int, input().split())
    if calc(Ax, Ay, Bx, By, preX, preY, x, y):
        num += 1
    preX, preY = x, y
if calc(Ax, Ay, Bx, By, preX, preY, preX0, preY0):
    num += 1

print(num // 2 + 1)