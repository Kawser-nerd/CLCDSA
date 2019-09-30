N, A, B = map(int, input().split())
S = [int(input()) for _ in range(N)]

S.sort()
if S[0] == S[-1]:
    print(-1)
else:
    P = B / (S[-1] - S[0])

    tmp = 0
    for i in range(N):
        tmp += P * S[i]

    Q = A - (tmp) / N
    
    print(P, Q)