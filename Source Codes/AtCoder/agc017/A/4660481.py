N, P = map(int, input().split())
A = list(map(int, input().split()))

k = len(list(filter(lambda x: x % 2 == 0, A)))
l = len(list(filter(lambda x: x % 2 == 1, A)))

if k == N:
    print(2 ** N if P == 0 else 0)
else:
    print(2 ** (N - 1))