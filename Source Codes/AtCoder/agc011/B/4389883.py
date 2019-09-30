n = int(input())
a = list(map(int, input().split()))

a.sort()
acum = [0] * (n+1)
for i in range(n):
    acum[i+1] += acum[i] + a[i]

ans = 1

for i in reversed(range(1, n)):
    if a[i] <= 2 * acum[i]:
        ans += 1
    else:
        break

print(ans)