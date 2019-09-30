K, S = map(int, input().split())

ans = 0
for i in range(K+1):
    for j in range(K+1):
        if S - i - j >= 0 and S - i - j <= K:
            ans += 1

print(ans)