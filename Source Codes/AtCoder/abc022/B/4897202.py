n = int(input())
visited = [0 for x in range(100001)]
ans = 0
for i in range(n):
    a = int(input())
    if visited[a - 1] != 0:
        ans += 1
    else:
        visited[a - 1] += 1

print(ans)