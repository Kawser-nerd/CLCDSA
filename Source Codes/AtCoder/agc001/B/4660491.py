N, X = list(map(int, input().split()))
ans = N
a, b = sorted([X, N - X])
while True:
    if b % a == 0:
        ans += (int(b / a) * 2 - 1) * a
        break
    else:
        ans += int(b // a) * a * 2
        a, b = b % a, a

print(ans)