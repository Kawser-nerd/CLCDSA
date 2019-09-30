A, K = map(int, input().split())
cnt = 0
if K > 0:
    while A < 2 * 10 ** 12:
        A += 1 + K * A
        cnt += 1
else:
    cnt = 2 * 10 ** 12 - A
print(cnt)