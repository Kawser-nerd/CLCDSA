N = int(input())
a = list(map(int, input().split()))
if sum(a) % N != 0:
    print(-1)
    exit()
m = sum(a) // N
ans = 0
for i in range(1, N):
    if m * i != sum(a[:i]):
        ans += 1
print(ans)