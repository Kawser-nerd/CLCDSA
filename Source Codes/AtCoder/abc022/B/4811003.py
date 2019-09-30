n = int(input())
l = [False] * (10 ** 5 + 1)
ans = 0
for _ in range(n):
    a = int(input())
    if l[a]: ans += 1
    l[a] = True
print(ans)