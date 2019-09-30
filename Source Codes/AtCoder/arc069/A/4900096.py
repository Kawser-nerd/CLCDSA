N, M = map(int, input().split())

if M <= 2 * N:
    print(M // 2)
else:
    print(N + (M - 2 * N) // 4)