x, y = map(int, input().split())

ans = 0
if x == y:
    ans = 0
elif x * y == 0:
    ans = abs(x) + abs(y) + (1 if x > y else 0)
elif x * y > 0:
    ans = abs(x - y) + (2 if x > y else 0)
else:
    ans = abs(x + y) + 1

print(ans)