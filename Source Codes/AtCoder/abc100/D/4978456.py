N, M = map(int, input().split())

X = [[0] * N for _ in range(8)]



for i in range(N):
    x, y, z = map(int, input().split())
    calc = [x+y+z, -x+y+z, x-y+z, -x-y+z,
            x+y-z, -x+y-z, x-y-z, -x-y-z]
    for j in range(8):
        X[j][i] = calc[j]

answer = 0
for i in range(8):
    a = sum(sorted(X[i], reverse=1)[:M])
    answer = max(a, answer)

print(answer)