from sys import setrecursionlimit
setrecursionlimit(10 ** 9)

n, a, b = [int(i) for i in input().split()]

if bin(a ^ b).count('1') % 2 == 0:
    print('NO')
    exit()

def dfs(i, a, b):
    if i == 1:
        return [a, b]
    d = (a ^ b) & -(a ^ b)
    ad = ((a & (~d ^ d - 1)) >> 1) + (a & d - 1)
    bd = ((b & (~d ^ d - 1)) >> 1) + (b & d - 1)
    c = ad ^ 1

    res1 = dfs(i - 1, ad, c)
    res2 = dfs(i - 1, c, bd)
    ans1 = [((r & ~(d - 1)) << 1) + (r & d - 1) + (d & a) for r in res1]
    ans2 = [((r & ~(d - 1)) << 1) + (r & d - 1) + (d & b) for r in res2]
    return ans1 + ans2

print('YES')
print(*dfs(n, a, b))