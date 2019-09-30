B = [list(map(int, input().split())) for i in range(2)]
C = [list(map(int, input().split())) for i in range(3)]

S = sum([sum(b) for b in B]) + sum([sum(c) for c in C])
memo = {}


def dfs(turn, board):
    # 9?????????????
    if turn == 10:
        Takahashi_score = 0
        for i in range(2):
            for j in range(3):
                if board[i][j] == board[i + 1][j]:
                    Takahashi_score += B[i][j]

        for i in range(3):
            for j in range(2):
                if board[i][j] == board[i][j + 1]:
                    Takahashi_score += C[i][j]

        return Takahashi_score

    # ????????
    if str(board) in memo:
        return memo[str(board)]

    scores = []
    for i in range(3):
        for j in range(3):
            # ?????????
            if board[i][j] is not None:
                continue

            # 1?? 0?×
            board[i][j] = turn % 2

            scores.append(dfs(turn + 1, board))

            # ??????????
            board[i][j] = None

    scores.sort()
    # ???????????????????????????????????
    ret = scores[-1] if turn % 2 else scores[0]
    memo[str(board)] = ret
    return ret


ans = dfs(1, [[None] * 3 for i in range(3)])
print(ans)
print(S - ans)