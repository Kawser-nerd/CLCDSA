from functools import lru_cache

s = []
h = 0
w = 0

def valid(x, y):
    if x < 0 or y < 0 or x >= h or y >= w:
        return False
    if s[x][y] == "#":
        return False
    return True

@lru_cache(maxsize = None)
def dp(x, y, player):
    if player == 0:
        res = 0
        if valid(x + 1, y):
            res = max(res, dp(x + 1, y, 1 - player))
        if valid(x + 1, y + 1):
            res = max(res, dp(x + 1, y + 1, 1 - player))
        if valid(x, y + 1):
            res = max(res, dp(x, y + 1, 1 - player))
        return res
    else:
        res = 1
        if valid(x + 1, y):
            res = min(res, dp(x + 1, y, 1 - player))
        if valid(x + 1, y + 1):
            res = min(res, dp(x + 1, y + 1, 1 - player))
        if valid(x, y + 1):
            res = min(res, dp(x, y + 1, 1 - player))
        return res

h, w  = map(int, input().split())
s = [input() for i in range(h)]
res = dp(0, 0, 0)
if  res == 1:
    print("First")
else:
    print("Second")