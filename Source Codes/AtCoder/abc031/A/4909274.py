A, D = map(int, input().split())
if A <= D:
    print((A + 1) * D)
else:
    print(A * (D + 1))