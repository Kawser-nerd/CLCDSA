n,k = map(int,input().split())
a = list(map(int,input().split()))

#dp[i]: [???i?????????????,smaller]
#smaller: {0:????K??????????,1:???????ok}
dp = [[0,0] for _ in range(42)]

for i in range(1,42):
    if dp[i-1][1] == 1:
        dp[i][1] = 1
    
    #ctr:i???1?A???
    ctr = 0
    for j in range(n):
        if (a[j]>>(41-i))&1 == 1:
            ctr += 1

    if ctr >= n-ctr:
        #i???0???
        dp[i][0] = dp[i-1][0] + ctr*(2**(41-i))
        if (k >> (41-i))&1 == 1:
            dp[i][1] = 1
    else:
        #i???1????
        if dp[i][1] == 1:
            #1???
            dp[i][0] = dp[i-1][0]+(n-ctr)*(2**(41-i))
        else:
            if (k >> (41-i))&1 == 1:
                #1???
                dp[i][0] = dp[i-1][0]+(n-ctr)*(2**(41-i))
            else:
                #1???????0???
                dp[i][0] = dp[i-1][0] + ctr*(2**(41-i))

print(dp[41][0])