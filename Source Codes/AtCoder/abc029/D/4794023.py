# python template for atcoder1
import sys
sys.setrecursionlimit(10**9)
input = sys.stdin.readline
# N?str
N = input()[:-1]
# L?N???
L = len(N)

# dp[i][j][k]?N?i????????if(j)??N???????????k??1?????????????
dp = [[[0]*(L+1) for _ in range(2)] for _ in range(L+1)]

dp[0][0][0] = 1

for dig in range(len(N)):
    for less in range(2):
        for num in range(len(N)):
            if dp[dig][less][num] == 0:
                continue
            elif less == 1:  # N?????
                dp[dig+1][1][num+1] += dp[dig][less][num]  # 1????dig+=1.num+=1
                dp[dig+1][1][num] += dp[dig][less][num] * \
                    9  # 1?????(9????) dig+=1
            else:  # N????????????????????????
                if N[dig] == '1':  # ???????1??
                    dp[dig+1][0][num+1] += dp[dig][less][num]  # 1???
                    dp[dig+1][1][num] += dp[dig][less][num]  # 0???
                elif N[dig] == '0':
                    dp[dig+1][0][num] += dp[dig][less][num]  # 0???????
                else:
                    # N[dig]????less??????????????less=1???
                    dp[dig+1][0][num] = dp[dig][less][num]
                    # 1?????(0~N[dig]?1????N[dig]-1????
                    dp[dig+1][1][num] = dp[dig][less][num]*(int(N[dig])-1)
                    dp[dig+1][1][num+1] += dp[dig][less][num]  # 1???

ans = 0
for less in range(2):
    for num in range(len(N)+1):
        if dp[len(N)][less][num]:
            ans += num*dp[len(N)][less][num]
print(ans)