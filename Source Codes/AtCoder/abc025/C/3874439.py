b = [tuple(map(int, input().split())) for _ in range(2)]
c = [tuple(map(int, input().split())) for _ in range(3)]
S = sum([sum(v) for v in b]) + sum([sum(v) for v in c])
memo = {}

def score(t):
    s = 0
    for i in range(2):
        for j in range(3):
            if t[i+1][j] == t[i][j]:
                s += b[i][j]
    for i in range(3):
        for j in range(2):
            if t[i][j+1] == t[i][j]:
                s += c[i][j]
    return s

def solve(t, turn=1):
    if str(t) in memo:
        return memo[str(t)]
    if turn == 10:
        return score(t)
    bs1 = 0
    bs2 = float('inf')
    for i in range(3):
        for j in range(3):
            if not t[i][j] is None:
                continue
            t[i][j] = turn % 2
            s = solve(t, turn + 1)
            t[i][j] = None
            bs1 = max(bs1, s)
            bs2 = min(bs2, s)
    ret = bs1 if turn % 2 else bs2
    memo[str(t)] = ret
    return ret

ret = solve([[None for _ in range(3)] for _ in range(3)])
print(ret)
print(S-ret)