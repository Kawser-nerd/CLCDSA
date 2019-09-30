THIS_X, THIS_Y = map(int, input().split(" "))
N = int(input())
XY = [list(map(int, input().split(" "))) for _ in range(N)]

min_num = 10**8
for i in range(N):
    x1, y1 = XY[i]
    x1, y1 = x1-THIS_X, y1-THIS_Y
    x2, y2 = XY[i-1]
    x2, y2 = x2-THIS_X, y2-THIS_Y
    d = abs(x1*y2 - x2*y1) / (abs(x1-x2)**2 + abs(y1-y2)**2)**(1/2)
    min_num = min(min_num, d)

print(min_num)