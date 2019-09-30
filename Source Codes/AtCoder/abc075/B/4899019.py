h, w = [int(n) for n in input().split()]

B = [['.'] * (w + 2)]
for i in range(h):
    s = ['.'] + list(input()) + ['.']
    B.append(s)
B.append(['.'] * (w + 2))

for i in range(1, h+1):
    for j in range(1, w+1):

        if B[i][j] == '#':
            continue
        else:
            
            B[i][j] = str((B[i-1][j-1:j+2] + [B[i][j-1]] + [B[i][j+1]] + B[i+1][j-1:j+2]) .count('#'))

#print(B)

for i in range(1, h+1):
    print(''.join(B[i][1:w+1]))