L, N = map(int, input().split())
X = [0]
for _ in range(N):
    X.append(int(input()))

s = [0] * (N + 1)
t = [0] * (N + 1)
for i in range(1, N + 1):
    s[i] = s[i-1] + X[i]
    t[i] = t[i-1] + (L - X[N - i + 1])
Y = [0] + [L - X[N - i] for i in range(N)]

# i >= 1


def get_d(s, x, i):
    if i == N:
        return x[N]
    a = i + (N - i) // 2
    return (
        2 * (s[a] - s[i-1] + L * (N - a) - s[N] + s[a]) -
        (x[a] if (N - i) % 2 == 0 else (L - x[a + 1]))
    )


ans = 0
for i in range(1, N + 1):
    ans = max(ans, get_d(s, X, i), get_d(t, Y, i))

print(ans)