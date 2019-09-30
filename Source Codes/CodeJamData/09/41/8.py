# Marius Damarackas (m.damarackas@gmail.com)
# Google CodeJam, Round 2, 2009-09-26

def make_swaps(matrix, i, j):
    moves = 0
    while j > i:
        matrix[j], matrix[j - 1] = matrix[j - 1], matrix[j]
        j -= 1
        moves += 1
    return moves

def last_one(row):
    positions = [pos for pos, num in enumerate(row) if num == '1']
    return 0 if len(positions) == 0 else max(positions)

def solve(matrix):
    moves = 0
    N = len(matrix)
    for i in range(0, N):
        for j in range(i, N):
            if last_one(matrix[j]) <= i:
                moves += make_swaps(matrix, i, j)
                break
    return moves

def main():
    file = open("input.in")
    tests = int(file.readline())
    for case in range(1, tests + 1):
        N = int(file.readline())
        matrix = [file.readline().strip() for i in range(N)]
        print("Case #", case, ": ", solve(matrix), sep="")

if __name__ == "__main__":
    main()
