Q, H, S, D = map(int, input().split())
N = int(input())
q, h, s, d = 4 * Q, 2 * H, S, D / 2
if d == min(q, h, s, d) and N >= 2:
    res = D * (N // 2) + (N % 2) * min(q, h, s)
else:
    res = N * min(q, h, s)
print(res)