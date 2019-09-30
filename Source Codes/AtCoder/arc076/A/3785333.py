N, M = map(int, input().split())

if abs(N - M) >= 2:
    print(0)

elif N == M:
    ans = 1
    for i in range(1,N+1):
        ans = (ans * i) % (10 ** 9 + 7)
    for i in range(1, M + 1):
        ans = (ans * i) % (10 ** 9 + 7)
    print((2 * ans) % (10 ** 9 + 7))
else:
    ans = 1
    for i in range(1,N+1):
        ans = (ans * i) % (10 ** 9 + 7)
    for i in range(1, M + 1):
        ans = (ans * i) % (10 ** 9 + 7)
    print(ans % (10 ** 9 + 7))