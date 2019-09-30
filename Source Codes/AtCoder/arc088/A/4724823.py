x, y = map(int, input().split())
ans = 1
a = x

for _ in range(61):
    a *= 2
    if a <= y:
        ans += 1
    else:
        break

print(ans)