def inpl(): return [int(i) for i in input().split()]
N, M = inpl()
if M < N:
    N, M = M, N
if N == 1:
    if M == 1:
        print(1)
    else:
        print(M-2)
elif N == 2:
    print(0)
else:
    print((N-2)*(M-2))