n = int(input())
if n % 2 == 0:
    ans = int((n // 2) ** 2)
else:
    ans = int(n // 2) * (n // 2 + 1)
print(ans)