H, W = map(int, input().split())
S = [''] * (H + 2)
S[0] = [''] * (W + 2)
for i in range(1, H + 1):
    S[i] = ['']
    S[i].extend(list(input()))
    S[i].extend([''])
S[H + 1] = [''] * (W + 2)

ans = [0] * H
for i in range(H):
    ans[i] = [0] * W

for i in range(1, H + 1):
    for j in range(1, W + 1):
        if S[i][j] == '.':
            ans[i - 1][j - 1] += S[i - 1][j - 1 : j + 2].count('#')
            ans[i - 1][j - 1] += S[i][j - 1 : j + 2].count('#')
            ans[i - 1][j - 1] += S[i + 1][j - 1 : j + 2].count('#')
        else:
            ans[i - 1][j - 1] = '#'

for i in range(H):
    for j in range(W):
        print(ans[i][j], end = '')
    print()