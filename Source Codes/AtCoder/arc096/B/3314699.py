# https://beta.atcoder.jp/contests/arc096/submissions/2706219
N, C = map(int, input().split())
X, V = zip(*(map(int, input().split()) for _ in range(N)))
R = [0] * (N + 1)
Rans = [0] * (N + 1)
for i in range(N):
    R[i + 1] = R[i] + V[i]
    Rans[i + 1] = max(Rans[i], R[i + 1] - X[i])

L = [0] * (N + 1)
Lans = [0] * (N + 1)
for i in range(N, 0, -1):
    L[i - 1] = L[i] + V[i - 1]
    Lans[i - 1] = max(Lans[i], L[i - 1] - (C - X[i - 1]))

ans_1 = max(Rans[N], Lans[0])
# ????????????
ans_2 = max(Lans[i + 1] + R[i + 1] - 2 * X[i] for i in range(N))
ans_3 = max(Rans[i - 1] + L[i - 1] - 2 * (C - X[i - 1])
            for i in range(N, 0, -1))
print(max(ans_1, ans_2, ans_3))