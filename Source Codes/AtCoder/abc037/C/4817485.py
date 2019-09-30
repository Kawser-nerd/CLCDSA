N, K = map(int, input().split())
a = list(map(int,input().split()))

s = [0]
total = 0
for i in range(N):
    total += a[i]
    s.append(total)


ans = 0
for i in range(N-K+1):
    ans += s[i+K] - s[i]
print(ans)