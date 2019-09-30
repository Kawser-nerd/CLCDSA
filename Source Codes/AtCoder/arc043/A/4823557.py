N, A, B = map(int, input().split())
S = sorted([int(input()) for i in range(N)])

if S[0] == sum(S) / len(S):
    print(-1)
else:
    diff = max(S) - min(S)
    P = B / diff
    Q = A - sum([i * P for i in S]) / len(S)
    print(P, Q)