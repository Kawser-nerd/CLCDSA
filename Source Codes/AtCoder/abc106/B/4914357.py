N = int(input())
odds = [i for i in range(1, N + 1) if i % 2 != 0]
ans = 0
for odd in odds:
    cnt = 0
    for bunbo in odds:
        if odd % bunbo == 0:
            cnt += 1
    if cnt == 8:
        ans += 1

print(ans)