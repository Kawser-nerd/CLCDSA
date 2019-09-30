""" AtCoder """

N, x = map(int, input().split())
a = list(map(int, input().split()))

a.sort()

ans = 0

for i in range(N):
    if i < N - 1:
        if x >= a[i]:
            ans += 1
            x -= a[i]
    else:
        if a[i] == x:
            ans += 1

print(ans)