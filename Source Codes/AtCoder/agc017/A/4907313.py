N, P = map(int, input().split())
A = [(int(a)) % 2 for a in input().split()]

DP = [[0, 0] for _ in range(N)] #DP[i][0]?i???0???????, DP[i][1]?1???????
DP[0][A[0]] += 1
DP[0][0] += 1
for i in range(1, N):
    if A[i] == 0:
        DP[i][0] = DP[i-1][0] * 2
        DP[i][1] = DP[i-1][1] * 2
    else:
        DP[i][0] = DP[i-1][1] + DP[i-1][0]
        DP[i][1] = DP[i-1][0] + DP[i-1][1]
print(DP[N-1][P])