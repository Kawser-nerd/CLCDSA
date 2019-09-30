def main():
    n,k = map(int,input().split())

    #dp[i][j][b]:i?????j?????????b:max??????????????
    dp = [[[0]*2 for i in range(k+2)] for _ in range(n+1)]

    #n???????????????
    for i in range(k+1):
        dp[n][i][1] = 1


    for i in range(n-1,-1,-1):
        for j in range(k+1):
            p = 1/(i+1)
            #out: i+1??? 1~i+1??max??
            out = max(dp[i+1][j+1][1], dp[i+1][j][0])*p
            
            dp[i][j][0] = dp[i+1][j][0] * (1-p) + out
            dp[i][j][1] = dp[i+1][j][1] * (1-p) + out
    print(dp[0][0][0])
if __name__ == '__main__':
    main()