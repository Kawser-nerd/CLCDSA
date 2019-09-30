K, S = map(int, input().split())
ans = 0
for x in range(K + 1):
    for y in range(K + 1):
        if (S - (x + y) <= K) and (0 <= S - (x + y)):
            ans += 1
print(ans)