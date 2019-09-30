A, B = map(int, input().split())
ans = [['#'] * 100 for _ in range(50)] + [['.'] * 100 for _ in range(50)]
for i in range(0, 50, 2):
    for j in range(0, 100, 2):
        if A > 1:
            ans[i][j] = '.'
            A -= 1

for i in range(51, 100, 2):
    for j in range(0, 100, 2):
        if B > 1:
            ans[i][j] = '#'
            B -= 1
print(100, 100)
for row in ans:
    print(*row, sep='')