H, W = map(int, input().split())
S = [['.'] * (W + 2)] + [['.'] + list(input()) + ['.'] for i in range(H)] + [['.'] * (W + 2)]

for i in range(1, H + 1):
    for j in range(1, W + 1):
        if S[i][j] == '.':
            S[i][j] = str([S[i - 1][j - 1], S[i - 1][j], S[i - 1][j + 1], S[i][j - 1], S[i][j + 1], S[i + 1][j - 1], S[i + 1][j], S[i + 1][j + 1]].count('#'))

for i in range(1, H + 1):
    print(''.join(S[i][1:W + 1]))