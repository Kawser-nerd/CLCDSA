N = int(input())
m = map(int, input().split())
ans = 0
for p in m:
    ans += max(0, 80 - p)
print(ans)