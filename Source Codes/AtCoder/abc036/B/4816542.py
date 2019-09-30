N = int(input())

A = [list(input()) for i in range(N)]

#B = [[] for i in range(N)]
for i in range(N):
    for j in range(N):
        #B[i][j] = A[j-N+1][i]
        #B[j][N-1-i] = A[i][j]
        print(A[N-j-1][i], end="")
    print()