A, B, C, K = map(int, input().split())
S, T = map(int, input().split())
ans = 0
if K <= (S + T):
    ans = (A * S) + (B * T) - (C * (S + T))
else:
    ans = (A * S) + (B * T)
print(ans)