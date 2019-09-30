a, b = map(int, input().split())

ans = a
if a > b:
    ans -= 1

print(ans)