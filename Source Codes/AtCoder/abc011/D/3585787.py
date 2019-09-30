from math import factorial

N, D = map(int, input().split())
X, Y = map(int, input().split())

if X % D or Y % D or (X//D+Y//D) % 2 != N % 2:
    print(0)
    exit()

X, Y = abs(X // D), abs(Y // D)
total = 0
for k in range(X%2, N+1, 2):
    x, y = k, N-k
    if x < X or y < Y:
        continue
    s = factorial(N) // factorial(k) // factorial(N-k)
    rx = (X + x) // 2
    s *= factorial(x) // factorial(rx) // factorial(x - rx)
    ry = (Y + y) // 2
    s *= factorial(y) // factorial(ry) // factorial(y - ry)
    total += s

print(total / 4**N)