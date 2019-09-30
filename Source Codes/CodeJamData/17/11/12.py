def empty_row(x):
    s = set([c for c in x])
    return len(s) == 1 and ('?' in s)


def fill_row(r):
    if empty_row(r):
        return r

    letters = []
    letters_set = set()

    for c in r:
        if c not in letters_set and c != '?':
            letters_set.add(c)
            letters.append(c)

    current = 0
    nr = []
    for i in range(len(r)):
        if r[i] == '?':
            nr.append(letters[current])
        else:
            nr.append(r[i])
            current = min(current + 1, len(letters_set) - 1)

    return nr


def testcase():
    n, m = [int(x) for x in input().split(" ")]
    board = []
    for i in range(n):
        board.append(input())

    for i in range(n):
        board[i] = fill_row(board[i])

    for i in range(n - 1):
        if empty_row(board[i + 1]) and not empty_row(board[i]):
            board[i + 1] = board[i]

    for i in reversed(range(1, n)):
        if empty_row(board[i - 1]):
            board[i - 1] = board[i]

    for r in board:
        print("".join(r))


t = int(input())

for num in range(t):
    print("Case #{num}: ".format(num=num + 1))
    testcase()
