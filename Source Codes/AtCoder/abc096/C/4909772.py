H, W = map(int, input().split(' '))

S = [[0 for j in range(W)] for i in range(H)]
for i in range(H):
    for j, sij in enumerate(input()):
        S[i][j] = sij

flag = True

for i in range(H):
    for j in range(W):
        if S[i][j] == '#':
            if 0 <= i-1 and S[i-1][j] == '#' or 0 <= j-1 and S[i][j-1] == '#' or j+1 < W and S[i][j+1] == '#' or i+1 < H and S[i+1][j] == '#':
                continue
            else:
                flag= False
                break
    if flag == False:
        break

if flag:
    print('Yes')
else:
    print('No')