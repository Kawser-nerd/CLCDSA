n, t = map(int, input().split())
time = list(map(int, input().split()))
ans, pre = 0, 0

if n == 1:
    print(t)
    exit()

pre = time[0]

for i in range(n):
    if i == 0:
        pass
    else:
        dist = time[i] - pre
        if dist > t:
            ans += t
        else:
            ans += dist
        if i == n-1:
            ans += t
        pre = time[i]

print(ans)