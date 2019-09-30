N, A, B, L = map(int, input().split())

for i in range(N):
    L = L / A * B

print(L if L > 10 ** (-6) else 0)