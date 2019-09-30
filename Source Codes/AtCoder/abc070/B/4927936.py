A, B, C, D = map(int, input().split())
ans = 0
for i in range(101):
    if A < i <= B and C < i <= D:
        ans += 1
print(ans)