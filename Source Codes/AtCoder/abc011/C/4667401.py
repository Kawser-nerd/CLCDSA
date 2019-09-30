N1 = int(input())
NG_list=[int(input()) for _ in range(3)]
if N1 in NG_list:
    print('NO')
else:
    dp = [1e5 for _ in range(N1+1)]
    dp[N1] = 0
    for i in range(N1, 0, -1):
        if i in NG_list:
            continue
        else:
            for j in range(1, 4):
                dp[i-j] = min(dp[i]+1, dp[i-j])
                
    if dp[0] <= 100:
        print('YES')
    else:
        print('NO')