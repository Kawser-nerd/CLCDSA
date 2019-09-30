import sys
input = sys.stdin.readline
inf = float('inf')

B = [list(map(int,input().split())) for _ in range(2)]
C = [list(map(int,input().split())) for _ in range(3)]
grid = [[-1]*3 for _ in range(3)]
note = {}

def sum2(table):
    res = 0
    for line in table:
        for p in line:
            res += p
    return res

def cal(table):
    score = 0
    for i in range(2):
        for j in range(3):
            if table[i+1][j] == table[i][j]:
                score += B[i][j]
            else:
                score -= B[i][j]
    for i in range(3):
        for j in range(2):
            if table[i][j+1] == table[i][j]:
                score += C[i][j]
            else:
                score -= C[i][j]
    return score
    
def rec(turn=0):
    if turn == 9:
        return cal(grid)
    if str(grid) in note:
        return note[str(grid)]
    option = inf if turn%2 else -inf
    for i,line in enumerate(grid):
        for j,p in enumerate(line):
            if p != -1:
                continue
            grid[i][j] = turn%2
            res = rec(turn+1)
            if turn%2:
                if res < option:
                    option = res
            else:
                if res > option:
                    option = res
            grid[i][j] = -1
    note[str(grid)] = option
    return option

sum_score = sum2(B) + sum2(C)
dif_score = rec()
X = (sum_score + dif_score) // 2
Y = (sum_score - dif_score) // 2
print(X)
print(Y)