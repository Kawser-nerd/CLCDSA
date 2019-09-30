N, L = map(int, input().split())
A = list(map(int, input().split()))


X = [A[i] + A[i + 1] for i in range(N - 1)]
if any(map(lambda x: x >= L, X)):
    print('Possible')

    for i, x in enumerate(X, start=1):
        if x >= L:
            xi = i
            break

    for i in range(1, xi):
        print(i)
    for i in reversed(range(xi + 1, N)):
        print(i)
    print(xi)

else:
    print('Impossible')