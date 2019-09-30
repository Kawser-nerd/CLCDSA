C_1 = [list(map(int, input().split())) for _ in range(3)]
C_2 = [[C_1[0][i], C_1[1][i], C_1[2][i]] for i in range(3)]  # ??
res = None
for C in C_1, C_2:
    for i in range(3):
        diff = [C_1[i][j] - C_1[(i + 1) % 3][j] for j in range(3)]
        for d in diff:
            if not d == diff[0]:
                res = 'No'
                break
        if res:
            break
    if res:
        break
if not res:
    res = 'Yes'
print(res)