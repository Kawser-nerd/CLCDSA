A, K = map(int, input().split())
t = A
if K == 0:
    print(2*10**12-A)
else:
    ans = 0
    while t < 2*10**12:
        t += 1 + K*t
        ans += 1
    print(ans)