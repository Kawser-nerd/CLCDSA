from collections import defaultdict

def calc_dp(board, seen):
    dp = [[1] * len(board[0]) for i in range(len(board))]
    foo = []
    for r in range(len(board) - 2, -1, -1):
        for c in range(len(board[0]) - 2, -1, -1):
            square = ((board[r][c] == board[r+1][c+1]) and
                      (board[r][c] != board[r][c+1]) and
                      (board[r][c] != board[r+1][c]))
            can_do = not (seen[r][c] or seen[r+1][c] or seen[r][c+1] or seen[r+1][c+1])
            if square and can_do:
                dp[r][c] = min(dp[r+1][c+1], dp[r+1][c], dp[r][c+1]) + 1
            foo.append((dp[r][c], -r, -c))
        foo.append((1, -r, -(len(board[0]) - 1)))
    for c in range(len(board[0])):
        foo.append((1, -(len(board) - 1), -c))
    best = -1, -1, -1
    for s, r, c in foo:
        if not seen[-r][-c] and (s, r, c) > best:
            best = s, r, c
    if best[0] == -1:
        return None
    s, r, c = best
    r = -r
    c = -c
    for x in range(s):
        for y in range(s):
            seen[r+x][c+y] = True
    return s
 
    

def solve(t, board):
    seen = [[False] * len(board[0]) for i in board]
    ans = defaultdict(int)
    while True:
        x = calc_dp(board, seen)
        if x is None:
            break
        ans[x] += 1
    print "Case #%d: %d" % (t, len(ans))
    for x, y in sorted(ans.items(), reverse=True):
        print x, y

T = int(raw_input())
for t in range(1, T+1):
    M, N = map(int, raw_input().split())
    board = []
    for m in range(M):
        row = []
        for c in raw_input():
            b = bin(int(c, 16))[2:]
            b = '0' * (4 - len(b)) + b
            row.extend(1 if x == '1' else 0 for x in b)
        board.append(row)
    solve(t, board)
