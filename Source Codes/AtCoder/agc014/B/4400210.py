N, M = map(int, input().split())
X = [0] * (10 ** 5)

for i in range(M):
    a, b = map(int, input().split())
    a, b = a - 1, b - 1
    X[a] += 1
    X[b] += 1

if all(map(lambda x: x % 2 == 0, X)):
    print('YES')
else:
    print('NO')