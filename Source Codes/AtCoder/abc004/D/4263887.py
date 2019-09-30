r, g, b = map(int,input().split())
def count(remaining, place):#remaining???????????????=j /dp[i-1][j]
    if remaining == 0:
        return 0
    elif 0 < remaining <= b:
        return abs(place-600)
    elif b < remaining <= b+g:
        return abs(place-500)
    elif b+g < remaining <= b+g+r:
        return abs(place-400)

#-500?0???
dp = [[10**8 for i in range(r+g+b+1)] for j in range(1000)]
dp[0][r+g+b] = 0
dp[0][r+g+b-1] = count(r+g+b,0)
for i in range(1,1000):
    if dp[i-1][0] != 10**8:
        dp[i][0] = dp[i-1][0]
    for j in range(1,r+g+b+1):
        if dp[i-1][j] != 10**8:
            dp[i][j] = min(dp[i-1][j], dp[i][j])
            dp[i][j-1] = min(dp[i-1][j]+count(j,i), dp[i][j-1])
    
print(dp[999][0])