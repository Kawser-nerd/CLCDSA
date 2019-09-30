N, K = map(int, input().split())

base = 0
length = 0
ans = 0

for i in range(N):
    item = int(input())
    if item > base:
        base = item
        length += 1
        if length >= K:
            ans += 1
    else:
        base = item
        length = 1
        if length >= K:
            ans += 1

print(ans)