n = int(input())
ls = [int(input()) for _ in range(n)]

def LIS(lst):
    import bisect
    dp = [lst[0]]
    for i in range(len(lst)):
        if lst[i] > dp[-1]:
            dp.append(lst[i])
        else:
            dp[bisect.bisect_left(dp, lst[i])] = lst[i]
    return len(dp)
print(len(ls) - LIS(ls))