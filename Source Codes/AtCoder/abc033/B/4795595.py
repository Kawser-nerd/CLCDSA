N = int(input())
S = [0] * N
P = [0] * N
for i in range(N):
    SP = input().split()
    S[i], P[i] = SP[0], int(SP[1])

print(S[P.index(max(P))] if max(P)*2 > sum(P) else "atcoder")