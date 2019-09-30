N = int(input())
m = 0
ans = 0
for i in range(N):
    p = int(input())
    if p > m:
        m = p
    ans += p
print(int(ans - m / 2))