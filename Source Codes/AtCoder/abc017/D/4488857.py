MOD = 1000000007


n,m = map(int,input().split())

f = [0]

for i in range(n):
    ff = int(input())
    f.append(ff)

flag = [False for i in range(m+1)]
dp = [0 for i in range(n+1)]

cnt = 0
right = 1
left = 1
sum = 0
dp[0] = 1
while(left < n+1):

    while right < n+1:     
        if (flag[f[right]]): break   
        flag[f[right]] = True
        sum = (sum + dp[right-1]) % MOD
        dp[right] = sum
        right += 1
    
    if(right == n+1):break

    while left < n+1:
        flag[f[left]]=False
        sum = (sum - dp[left-1]) % MOD
        
        if(f[left] == f[right]):
            left += 1
            break
        left += 1
        
print(dp[n])