N = int(input())
ans = 0
prev = 0
for _ in range(N):
    A = int(input())
    if A == 0:
        prev = 0
        continue
    A += prev
    ans += A // 2
    prev = A % 2
print(ans)