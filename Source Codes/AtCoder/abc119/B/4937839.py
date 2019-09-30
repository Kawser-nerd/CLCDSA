N = int(input())
A = [list(map(str, input().split())) for _ in range(N)]
ans = 0

for value, unit in A:
    if unit == "BTC":
        ans += float(value)*380000
    else:
        ans += float(value)

print(ans)