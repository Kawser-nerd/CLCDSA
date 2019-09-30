a, b = map(int, input().split())
for i in range(1, 13):
    if a > b:
        ans = a - 1
    else:
        ans = a
print(ans)