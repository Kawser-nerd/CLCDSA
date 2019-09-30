n, m = map(int, input().split())
x, y = map(int, input().split())
a = list(map(int, input().split()))
b = [-y] + list(map(int, input().split()))

p = 0
q = 0
ans = 0
while 1:
    while p < n:
        if a[p] >= b[q] + y:
            break
        else:
            p += 1
    else:
        break

    while q < m + 1:
        if a[p] + x <= b[q]:
            ans += 1
            break
        else:
            q += 1
    else:
        break

print(ans)