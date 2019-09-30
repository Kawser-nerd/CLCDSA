N, M = map(int, input().split())
X = list(map(int, input().split()))
X.sort()
t = [0] * (M - 1)
for i in range(1, M):
    t[i - 1] = X[i] - X[i - 1]
t.sort(reverse=True)
print(sum(t[N - 1:]))