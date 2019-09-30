import bisect


def solve(k, aaa):
    aaa = aaa[:bisect.bisect_left(aaa, k)]

    dp = [False] * k
    dp[0] = True
    curr_max = 0
    ans = len(aaa)
    for i, a in reversed(list(enumerate(aaa))):
        if curr_max + a >= k:
            ans = i
        f = True
        for j in range(min(curr_max, k - a - 1), -1, -1):
            if dp[j]:
                dp[j + a] = True
                if f:
                    curr_max = max(curr_max, j + a)
                    f = False
    return ans


n, k = map(int, input().split())
aaa = list(map(int, input().split()))
aaa.sort()

print(solve(k, aaa))