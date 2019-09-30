from itertools import combinations

N = int(input())
XY = [list(map(int, input().split(" "))) for _ in range(N)]

count = 0
for a, b, c in combinations(XY, 3):
    x1, y1 = a[0]-c[0], a[1]-c[1]
    x2, y2 = b[0]-c[0], b[1]-c[1]
    s = abs(x1*y2 - y1*x2)
    # if area > 0:
    #     print(area, (x1, y1), (x2, y2), (x3, y3))
    if s != 0 and s%2==0:
        # print(area, (x1, y1), (x2, y2), (x3, y3))
        # print((x4, y4), (x5, y5))
        count += 1
    
print(count)