def rec_memo(N):
    dp = [[[-1 for _ in range(2)] for _ in range(2)] for _ in range(len(N)+1)]
    def rec(N, k = 0, tight = True, flag = False):
        if k == len(N):
            return flag
        if ~dp[k][tight][flag]:
            return dp[k][tight][flag]
        res = 0
        if tight:
            r = int(N[k])
        else:
            r = 9
        for i in range(0, r+1):
            res += rec(N, k+1, tight and i == r, flag or i == 4 or i == 9)
        dp[k][tight][flag] = res
        return res
    return rec(N)

A, B = input().split()
print(rec_memo(B) - rec_memo(str(int(A)-1)))