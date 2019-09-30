import sys
sys.setrecursionlimit(10**6)

H, W = map(int, input().split())
S = [list(input()) for i in range(H)]
memo = [[None for j in range(W)] for i in range(H)]


def judge(x, y):
    # ??????????
    if x >= W or y >= H or S[y][x] == "#":
        return True

    if memo[y][x] is not None:
        return memo[y][x]

    result = False
    
    # ??
    if not judge(x+1, y+1):
        result = 1
        
    # ?
    if not judge(x+1, y):
        result = True

    # ?
    if not judge(x, y+1):
        result = True


    memo[y][x] = result
    return result


print("First" if judge(0, 0) else "Second")