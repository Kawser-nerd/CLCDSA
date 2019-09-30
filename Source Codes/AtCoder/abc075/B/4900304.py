H, W = list(map(int, input().split(' ')))
S = [[] for i in range(H)]
for i in range(H):
    S_temp = input()
    for s in S_temp:
        S[i].append(s)

T = [[0 for j in range(W)] for i in range(H)]
for i in range(H):
    for j, sj in enumerate(S[i]):
        if sj != '.':
            T[i][j] = sj
            continue

        count = 0
        if 0 <= i-1 and 0 <= j-1 and S[i-1][j-1] == '#':
            count += 1
        if 0 <= i-1 and S[i-1][j] == '#':
            count += 1
        if 0 <= i-1 and j+1 < W and S[i-1][j+1] == '#':
            count += 1
        if 0 <= j-1 and S[i][j-1] == '#':
            count += 1
        if j+1 < W and S[i][j+1] == '#':
            count += 1
        if i+1 < H and 0 <= j-1 and S[i+1][j-1] == '#':
            count += 1
        if i+1 < H and S[i+1][j] == '#':
            count += 1
        if i+1 < H and j+1 < W and S[i+1][j+1] == '#':
            count += 1
            
        T[i][j] = count

for i in range(H):
    for j in range(W):
        print(T[i][j], end='')
    print('')