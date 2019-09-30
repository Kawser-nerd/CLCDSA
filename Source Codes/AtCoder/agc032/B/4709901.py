N = int(input())

matrix = [[1 for i in range(N)] for i in range(N)]
for i in range(N):
    matrix[i][i] = 0

if N%2==0:
    for i in range(N):
        matrix[i][N-i-1] = 0
else:
    for i in range(N-1):
        matrix[i][N-i-2] = 0

print(int((N*(N-1)/2)-int(N/2)))
for i in range(N):
    for j in range(i+1,N):
        if matrix[i][j] == 1:
            print(i+1,j+1)