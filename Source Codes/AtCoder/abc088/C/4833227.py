c = [[0, 0, 0], [0, 0, 0], [0, 0, 0]]

for i in range(0, 3):
    c[i] = [int(j) for j in input().split(" ")]

f = True
for i in range(0, 2):
    f = f and c[i][0] - c[i][1] == c[i + 1][0] - c[i + 1][1]
    f = f and c[i][1] - c[i][2] == c[i + 1][1] - c[i + 1][2]

for i in range(0, 2):
    f = f and c[0][i] - c[1][i] == c[0][i + 1] - c[1][i + 1]
    f = f and c[1][i] - c[2][i] == c[1][i + 1] - c[2][i + 1]

if f:
    print("Yes")
else:
    print("No")