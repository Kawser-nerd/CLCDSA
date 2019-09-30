# coding: utf-8
N, H = map(int, input().split())
A, B, C, D, E = map(int, input().split())
ans = C * N
for i in range(N + 1):
    j = max((E * (N - i) - B * i - H) // (D + E) + 1, 0)
    ans = min(ans, A * i + C * j)
print(ans)