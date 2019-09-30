N, M = [int(x) for x in input().split()]

if N == 1 and M == 1:
    print(1)
elif N == 1 or M == 1:
    print(max(N, M) - 2)
elif N == 2 or M == 2:
    print(0)
else:
    print((N-2) * (M-2))