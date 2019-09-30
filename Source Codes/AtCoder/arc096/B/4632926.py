n, c = map(int, input().split())
xv = [list(map(int, input().split())) for i in range(n)]
dx = []
dy = []
for i in range(n):
    if i == 0:
        dx.append(xv[i][0])
        dy.append(c - xv[-i-1][0])
    else:
        dx.append(xv[i][0]-xv[i-1][0])
        dy.append(-xv[-i-1][0] + xv[-i][0])
right = [0]
left = [0]
for i in range(n):
    r = right[-1] + xv[i][1] - dx[i]
    l = left[-1] + xv[-i-1][1] - dy[i]
    right.append(r)
    left.append(l)
for i in range(1,n+1):
    right[i] = max(right[i-1], right[i])
    left[i] = max(left[i-1], left[i])

ans = 0
for i in range(1,n+1):
    a1 = right[i]
    a2 = right[i] - xv[i-1][0] + left[n-i]
    a3 = left[i]
    a4 = left[i] - (c - xv[-i][0]) + right[n-i]
    ans = max(ans,a1,a2,a3,a4)
print(ans)