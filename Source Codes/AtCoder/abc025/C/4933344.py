def score(board: list, B: list, C: list)->int:
    '''??? board ????? o ?????????'''
    s = 0
    for i in range(3):
        for j in range(3):
            if i < 2 and board[i][j] == board[i+1][j]:
                s += B[i][j]
            if j < 2 and board[i][j] == board[i][j+1]:
                s += C[i][j]
    return s


def board2str(board: list)->int:
    '''board ?????????'''
    s = ''
    for i in range(3):
        for j in range(3):
            if board[i][j] == True:
                s += 'o'
            elif board[i][j] == False:
                s += 'x'
            else:
                s += '-'
    return s


def twins_and_oxgame(B: list, C: list)->tuple:
    S = sum(sum(b) for b in B) + sum(sum(c) for c in C)

    memo = {}
    board = [[None] * 3 for _ in range(3)]

    def dfs(turn: int)->int:
        if board2str(board) in memo:
            return memo[board2str(board)]

        if turn == 10:
            return score(board, B, C)

        max_s, min_s = -float('inf'), float('inf')
        for i in range(3):
            for j in range(3):
                if board[i][j] is not None:
                    # already defined
                    continue
                board[i][j] = turn % 2 == 1
                s = dfs(turn+1)
                board[i][j] = None

                max_s = max(max_s, s)
                min_s = min(min_s, s)

        memo[board2str(board)] = max_s if turn % 2 == 1 else min_s
        return memo[board2str(board)]

    ret = dfs(1)
    return ret, S - ret


if __name__ == "__main__":
    B = [[int(s) for s in input().split()] for _ in range(2)]
    C = [[int(s) for s in input().split()] for _ in range(3)]
    a, b = twins_and_oxgame(B, C)
    print(a)
    print(b)