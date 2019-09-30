N = int(input())
a = list(map(int, input().split()))

l = 1
r = 1
ans = 0
while l <= N:
    while l <= r and r < N and a[r-1] < a[r]:
        r += 1
    ans += r-l+1
    if r == l: r += 1
    l += 1

print(ans)