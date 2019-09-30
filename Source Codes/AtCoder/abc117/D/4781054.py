N, K = map(int, input().split())
A = list(map(int, input().split()))

x = 0
b = 1<<50
for _ in range(50):
    b = b>>1
    if x+b>K:
        continue

    cnt = 0
    for a in A:
        if a & b:
            cnt += 1
    if cnt < N/2:
        x += b

ans = 0
for a in A:
    ans += x^a

print(ans)