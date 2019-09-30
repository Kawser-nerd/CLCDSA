N = int(input())
xy = [[int(x) for x in input().split()] for _ in range(N)]
ans = 0
for i in range(N):
    for j in range(i+1, N):
        for k in range(j+1, N):
            t = (xy[j][0]-xy[i][0])*(xy[k][1]-xy[i][1]) - \
                (xy[j][1]-xy[i][1])*(xy[k][0]-xy[i][0])
            if t % 2 == 0 and t != 0:
                ans += 1
print(ans)