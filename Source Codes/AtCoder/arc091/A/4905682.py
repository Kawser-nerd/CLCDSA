N, M = map(int, input().split())

if N == 1 and M == 1:
    print(1)
elif N == 1 and M > 1:
    print(M-2)
elif N > 1 and M == 1:
    print(N-2)
else:
    print((N-2)*(M-2))