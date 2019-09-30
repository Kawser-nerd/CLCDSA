K, S = map(int, input().split())

ans = 0
for x in range(K+1):
    for y in range(K+1):
        x_y = x + y
        if x_y > S:
            break
        if S - x_y <= K:
            ans += 1

print(ans)