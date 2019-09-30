N, A, B = map(int, input().split())
S = [int(input()) for _ in range(N)]
S = sorted(S)

if S[0] != S[-1]:
    P = B/(S[-1]-S[0])
    Q = A - P*sum(S)/N
    print(P, Q)
else:
    print(-1)