H, W = map(int, input().split())
S = ['.' + input() + '.' for i in range(H)]
S.insert(0, '.' * (W + 2))
S.insert(len(S), '.' * (W + 2))
def mine(x):
    if x == '#':
        count.append(1)
for i in range(1, H+1):
    tmp = ''
    for j in range(1, W+1):
        if S[i][j] == '#':
            tmp += '#'
        else:
            count = []
            mine(S[i-1][j-1]); mine(S[i-1][j]); mine(S[i-1][j+1])
            mine(S[i][j-1]);                    mine(S[i][j+1])
            mine(S[i+1][j-1]); mine(S[i+1][j]); mine(S[i+1][j+1])
            tmp += str(sum(count))
    print(tmp)