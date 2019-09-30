n, k = map(int, input().split())
a = list(map(int, input().split()))
cnt = [0] * 50

for i in a:
    for j in range(50):
        if i & (1 << j) == 0:
            cnt[j] += 1 << j
        else:
            cnt[j] -= 1 << j

gg = []
for i in range(50):
    gg.append([cnt[i], i])
gg.sort(reverse = True)

ans = 0
for i in gg:
    if i[0] < 0:
        break
    if (1 << i[1]) <= k:
        k -= 1 << i[1]
        ans += i[0]

print(ans + sum(a))