N, M = map(int, input().split())
a, b, c, d = [], [], [], []
for i in range(N):
    x, y = map(int, input().split())
    a.append(x)
    b.append(y)
for i in range(M):
    x, y = map(int, input().split())
    c.append(x)
    d.append(y)
    
for i in range(N):
    ans = 0
    tmp = 10 ** 10
    for j in range(M):
        if abs(a[i] - c[j]) + abs(b[i] - d[j]) < tmp:
            tmp = abs(a[i] - c[j]) + abs(b[i] - d[j])
            ans = j + 1
    print(ans)