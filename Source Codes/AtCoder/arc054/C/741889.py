n = int(input())
a = [list(input()) for i in range(n)]
for i in range(n):
    for j in range(n):
        a[i][j] = ord(a[i][j]) - ord('0')

ans = True
for i in range(n):
    u = i
    while u < n and a[u][i] == 0:
        u += 1
    if u == n:
        ans = False
        break

    for j in range(u + 1, n):
        if a[j][i] == 1:
            a[j] = [p^q for p, q in zip(a[j], a[u])]
    a[i], a[u] = a[u], a[i]

if ans:
    print("Odd")
else:
    print("Even")