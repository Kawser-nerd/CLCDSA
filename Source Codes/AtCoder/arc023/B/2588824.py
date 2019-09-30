r, c, d = map(int, input().split())
a = []
for i in range(r):
    a.append(list(map(int, input().split())))
# for i in a:
#     print(i)

if d % 2 == 0:
    ans = a[0][0]
else:
    ans = max(a[1][0], a[0][1])
for i in range(d):
    for j in range(d):
        if i >= r or j >= c:
            break
        if i + j <= d and (i + j) % 2 == d % 2:
            ans = max(ans, a[i][j])
print(ans)