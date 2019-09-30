N, M = map(int, input().split())
B = [list(map(int, list(input()))) for i in range(N)]
A = [[0] * M for i in range(N)]

for i in range(1, N-1):
    for j in range(1, M-1):
        x = min(B[i+1][j], B[i-1][j], B[i][j+1], B[i][j-1])
        A[i][j] += x
        B[i+1][j] -= x
        B[i-1][j] -= x
        B[i][j+1] -= x
        B[i][j-1] -= x

for a in A:
    print("".join(map(str, a)))