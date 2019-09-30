n = int(input())

box = [list(map(int, input().split())) for _ in range(n)]

box.sort(key=lambda x: x[0], reverse=True)
box.sort(key=lambda x: x[1])

INF = float('inf')
ans = [INF] * (n+10)

for h, w in box:
    left = -1
    right = n
    while right - left > 1:
        mid = (left + right) // 2
        if h <= ans[mid]:
            right = mid
        else:
            left = mid
    ans[right] = h

count = 0
for i in range(n):
    if ans[i] == INF:
        break
    count += 1

print(count)