C = int(input())

ans = [0, 0, 0]
for _ in range(C):
    item = list(map(int, input().split()))
    item.sort()
    for i in range(3):
        ans[i] = max(ans[i], item[i])

print(ans[0] * ans[1] * ans[2])