A, B, C, K = map(int, input().split())
S, T = map(int, input().split())

if S + T >= K:
    A -= C
    B -= C

print(S*A + T*B)