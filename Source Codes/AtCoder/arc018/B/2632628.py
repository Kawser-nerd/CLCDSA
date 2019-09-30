N = int(input())
XY = [list(map(int, input().split())) for i in range(N)]

ans = 0
for i in range(N-2):
    for j in range(i+1, N-1):
        for k in range(j+1, N):
            x1, y1 = XY[i]
            x2, y2 = XY[j]
            x3, y3 = XY[k]
            area = abs((x2-x1)*(y3-y1) - (x3-x1)*(y2-y1))
            if area != 0 and area % 2 == 0:
                ans += 1

print(ans)