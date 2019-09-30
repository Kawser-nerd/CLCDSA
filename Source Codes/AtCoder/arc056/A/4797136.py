A, B, K, L = map(int, input().split())

cnt = 0
ans = float('inf')
while True:
    if K >= L * cnt:
        tmp = (K - L * cnt) * A + cnt * B
    else:
        tmp = cnt * B
    ans = min(ans, tmp)
    if L * cnt > K:
        break
    cnt += 1
    
print(ans)