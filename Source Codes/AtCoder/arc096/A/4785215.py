A, B, C, X, Y = map(int, input().split())

best = 10**9
for c in range(max(X, Y)*2+1):
    a = X-c
    b = Y-c
    if a < 0:
        a = 0
    if b < 0:
        b = 0
    p = A*a + B*b + C*c*2
    if p < best:
        best = p

print(best)