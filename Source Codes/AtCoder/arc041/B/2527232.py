def solve(N, M, board):
    before = [[0 for _ in range(M)] for _ in range(N)]
    for i in range(N):
        for j in range(M):
            v = board[i][j]
            if v > 0:
                before[i+1][j] = v
                board[i][j] -= v
                board[i+2][j] -= v
                board[i+1][j-1] -= v
                board[i+1][j+1] -= v

    return before


if __name__ == '__main__':
    N, M = map(int, input().split())
    board = [
        list(map(int, list(input())))
        for _ in range(N)
    ]
    ans = solve(N, M, board)
    for a in ans:
        print(*a, sep="")