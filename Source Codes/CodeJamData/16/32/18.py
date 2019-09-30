T = int(input())
for test in range(1, T + 1):
    B, M = [int(x) for x in input().split()]

    print("Case #%d: " % test, end="")

    if M > (2**(B - 2)):
        print("IMPOSSIBLE")
        continue
    A = [[0] * B for _ in range(B)]

    for i in range(0, B):
        for j in range(i + 1, B):
            A[i][j] = 1
    if M < 2**(B - 2):
        A[0][B - 1] = 0
        for i in range(B - 2):
            if (1 << i) & M:
                A[0][B - i - 2] = 1
            else:
                A[0][B - i - 2] = 0
    print("POSSIBLE")
    for i in range(B):
        print("".join([str(x) for x in A[i]]))
