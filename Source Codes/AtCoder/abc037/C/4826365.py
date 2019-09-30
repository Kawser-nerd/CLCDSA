N, K = map(int, input().split())
a = list(map(int, input().split()))
l = [a[0]]
for i in range(N - 1):
    l.append(l[i] + a[i + 1])
ans = l[K - 1]
for i in range(N - K):
    ans += l[i + K] - l[i]

print(ans)