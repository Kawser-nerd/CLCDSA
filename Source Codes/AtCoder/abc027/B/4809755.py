n = int(input())
a = list(map(int, input().split()))

if len(set(a)) == 1:
    print(0)
elif sum(a) % n != 0:
    print(-1)
else:
    ans = 0
    x = sum(a) // n
    for i in range(1, n):
        if sum(a[:i]) > x * i:
            ans += 1
        if sum(a[i:]) > x * (n - i):
            ans += 1
    print(ans)