s = list(input())
n = int(input())
a, b = (n - 1) // 5, (n - 1) % 5
ans = s[a] + s[b]
print(ans)