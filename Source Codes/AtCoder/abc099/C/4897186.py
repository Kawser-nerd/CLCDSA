N = int(input())
ans = N
for i in range(N + 1):
    cnt = 0
    t = i
    while t > 0:
        cnt += t % 6
        t //= 6
    j = N - i
    while j > 0:
        cnt += j % 9
        j //= 9
    ans = min(ans, cnt)
print(ans)