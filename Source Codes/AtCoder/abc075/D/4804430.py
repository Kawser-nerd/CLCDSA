n, k = map(int, input().split())
p = [list(map(int, input().split())) for i in range(n)]
ans = float("inf")

p.sort()
for i in range(n-k+1):
    for j in range(i+k-1, n):
        x = p[j][0] - p[i][0]
        yl = sorted(p[i:j+1],key=lambda x:x[1])
        for l in range(len(yl)-k+1):
            y = yl[l+k-1][1] - yl[l][1]
            ans = min(ans, y*x)
print(ans)