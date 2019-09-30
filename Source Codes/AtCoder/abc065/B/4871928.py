n = int(input())
a = [int(input()) for _ in range(n)]
ans = -1
ai = 0
for i in range(n):
    ai = a[ai] - 1
    if ai == 1:
        ans = i + 1
        break
print(ans)