T = int(input())

for test in range(1, T + 1):
    N = int(input())
    A = [int(x) for x in input().split()]

    print("Case #%d: " % test, end="")
    if N > 2:
        while sum(A) > 2:
            best = -1
            where = None
            for i in range(N):
                if A[i] > best:
                    best = A[i]
                    where = i
            print(chr(ord('A') + where), end=" ")
            A[where] -= 1
        for i in range(N):
            if A[i] > 0:
                print(chr(ord('A') + i), end="")
        print()
    else:
        for i in range(A[0]):
            print("AB ", end="")
        print()
