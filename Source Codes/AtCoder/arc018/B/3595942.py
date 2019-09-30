def is_area_integer(p1, p2, p3):
    p12 = [p2[0] - p1[0], p2[1] - p1[1]]
    p13 = [p3[0] - p1[0], p3[1] - p1[1]]
    area = abs(p12[0] * p13[1] - p12[1] * p13[0])
    if 0 == area:
        return False
    return 0 == area % 2


n = int(input())
grid = [list(map(int, input().split())) for _ in range(n)]

count = 0
for i in range(n):
    for j in range(i, n):
        for k in range(j, n):
            if is_area_integer(grid[i], grid[j], grid[k]):
                count += 1
print(count)