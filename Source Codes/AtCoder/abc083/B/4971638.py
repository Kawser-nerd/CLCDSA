N, A, B = map(int, input().split())
ans = 0
for i in range(1, N+1):
    N10000 = i // 10000
    N1000 = i // 1000 - N10000 * 10
    N100 = i // 100 - N10000 * 100 - N1000 * 10
    N10 = i // 10 - N10000 * 1000 - N1000 * 100 - N100 * 10
    N1 = i - N10000 * 10000 - N1000 * 1000 - N100 * 100 - N10 * 10
    if A <= N1 + N10 + N100 + N1000 + N10000 <= B:
        ans += i
print(ans)