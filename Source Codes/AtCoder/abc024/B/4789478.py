N, T = map(int, input().split())
a = [int(input()) for i in range(N)]
cnt = 0
for i in range(N - 1):
    if a[i + 1] - a[i] > T:
        cnt += T
    else:
        cnt += a[i + 1] - a[i]

print(cnt + T)