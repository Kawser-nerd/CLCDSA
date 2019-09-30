matrix = [[x for x in map(int, input().split())] for _ in range(3)]

matrix = sorted(matrix)
for i in range(1, 3):
    diff = matrix[i][0] - matrix[0][0]
    for j in range(3):
        if matrix[i][j] != matrix[0][j] + diff:
            print('No')
            exit()
print('Yes')