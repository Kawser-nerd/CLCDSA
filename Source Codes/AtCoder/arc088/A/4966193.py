x, y = map(int, input().split())
ans = 0

while x <= y:
    x *= 2
    ans += 1

print(ans)