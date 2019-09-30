N, K = map(int, input().split())
A = [int(a) for a in input().split()]

Plus, Whole = [0], [0]
for i in range(N):
    Plus.append(Plus[-1] + max(A[i], 0))
    Whole.append(Whole[-1] + A[i])

Score = max(max(0, Whole[K] - Whole[0]) + Plus[N] - Plus[K], Plus[N-K] - Plus[0] + max(0, Whole[N] - Whole[N-K]))
for i in range(1, N-K):
    temp = Plus[i] + max(0, Whole[i+K] - Whole[i]) + Plus[N] - Plus[i+K]
    Score = max(Score, temp)

print(Score)