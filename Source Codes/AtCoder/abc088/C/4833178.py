c = [list(map(int, input().split())) for _ in range(3)]
x = c[1][0] - c[0][0]
y = c[2][0] - c[0][0]
for i in range(3):
    c[1][i] -= x
    c[2][i] -= y
if c[0] == c[1] == c[2]:
    print('Yes')
else:
    print('No')