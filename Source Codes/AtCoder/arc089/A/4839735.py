N = int(input())
tmp = [[int(i) for i in input().split()] for i in range(N)]
tmp.insert(0, [0, 0, 0])
ans = 'Yes'

for i in range(N):
    t = tmp[i+1][0] - tmp[i][0]
    dx = abs(tmp[i+1][1] - tmp[i][1])
    dy = abs(tmp[i+1][2] - tmp[i][2])
    d = dx + dy
    if t < d \
    or t % 2 != d % 2:
        ans = 'No'
print(ans)