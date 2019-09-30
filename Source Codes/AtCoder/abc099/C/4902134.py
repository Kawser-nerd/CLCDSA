import sys
stdin = sys.stdin
 
sys.setrecursionlimit(10**5) 
 
def li(): return map(int, stdin.readline().split())

N = int(stdin.readline())
large = float('inf')
memo = {}
def cal_count(total):
    global memo
    if total in memo: return memo[total]
    if total < 0: return large
    if total == 0: return 0
    cans = []
    for i in range(1, 8):
        if 6 ** i > total: break
        cans.append(cal_count(total - 9 ** i))
        cans.append(cal_count(total - 6 ** i))
    cans.append(cal_count(total - 1))
    res = min(cans) + 1
    memo[total] = res
    return res
cnt = cal_count(N)
print(cnt)