A = []

for i in range(4):
    A.append(list(map(str, input().split())))

B = [['.', '.', '.', '.'], ['.', 'o', 'o', '.'], ['.', 'x', 'x', '.'], ['.', '.', '.', '.']]

for i in range(4):
    for j in range(4):
        B[3-i][3-j] = A[i][j]

for i in range(4):
    print(B[i][0] + ' ' + B[i][1] + ' ' + B[i][2] + ' ' + B[i][3])