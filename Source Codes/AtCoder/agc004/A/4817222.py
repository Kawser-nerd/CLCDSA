A = list(map(int, input().split()))

if all([i % 2 for i in A]):
    A.sort()
    print(A[0] * A[1])
else:
    print(0)