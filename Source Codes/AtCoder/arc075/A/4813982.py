n=int(input())
s=[int(input()) for i in range(n)]
memo=[[-1]*20000 for i in range(200)]
def dp(score, i):
    if i==n:
        if score%10==0:
            memo[i][score]=0
            return 0
        else:
            memo[i][score]=score
            return score
    if memo[i][score]>=0:
        return memo[i][score]
    memo[i][score]=max(dp(score+s[i-1], i+1), dp(score, i+1))
    return memo[i][score]
print(dp(0,0))