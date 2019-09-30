def cal_score(board):
    dai = 0
    ko = 0
    for i in range(2):
        for j in range(3):
            if board[i][j] == board[i+1][j]:
                dai += b[i][j]
            else:
                ko += b[i][j]
    for i in range(3):
        for j in range(2):
            if board[i][j] == board[i][j+1]:
                dai += c[i][j]
            else:
                ko += c[i][j]
    return (dai, ko)

def dfs(board, chokudai_turn, turn_n):
    global dp
    if dp.get(str(board)):
        return dp[str(board)]
    if turn_n == 10:
        return cal_score(board)
    scores = []
    for i in range(3):
        for j in range(3):
            if board[i][j] != '':
                continue
            board[i][j] = chokudai_turn
            scores.append({'score': dfs(board, not chokudai_turn, turn_n + 1), 'board': board})
            board[i][j] = ''
    ans = max(scores, key=lambda x: x['score'][0 if chokudai_turn else 1])
    dp[str(ans['board'])] = ans['score']
    return ans['score']

b = []
c = []
for _ in range(2):
    b.append([int(x) for x in input().split()])
for _ in range(3):
    c.append([int(x) for x in input().split()])

board = [[''] * 3 for _ in range(3)]
dp = {}
chokudai, chokuko = dfs(board, True, 1)
print(chokudai)
print(chokuko)