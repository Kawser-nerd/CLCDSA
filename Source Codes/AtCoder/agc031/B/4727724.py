def solve():
 n = int(input())
 c = [int(input()) for _ in range(n)]
 mod = 10**9 +7
 dp = [1]*n
 dp[0] = 1
 place = [-1]*200001

 for i in range(n):    
    if place[c[i]-1] != -1:
      if place[c[i]-1] == i-1:
        dp[i] = dp[i-1]
      else:
        dp[i] = (dp[i-1]+dp[place[c[i]-1]])%mod
        
    else:
     dp[i] = dp[i-1]
    place[c[i]-1] = i
 #print(dp)
 #print(place)
 return dp[-1]%mod

print(solve())