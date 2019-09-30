N = int(input())
inputs = [input() for _ in range(N)]

s = 0
for j in range(9):
    b = ''
    for i in range(N):
        c = inputs[i][j]
        if c == 'x' or (c == 'o' and b != 'o'):
            s += 1
        b = c

print(s)