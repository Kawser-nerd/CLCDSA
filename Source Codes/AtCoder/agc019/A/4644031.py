Q, H, S, D = list(map(int, input().split()))
N = int(input())

H = min(H, 2 * Q)
S = min(S, 2 * H)
D = min(D, 2 * S)

Ans = (N // 2) * D + (N % 2) * S
print(Ans)