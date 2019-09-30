N, M = map(int, input().split())
#f_0, f_1, ..., f_N-1
f = [int(input()) for i in range(N)]

#f_j, f_j+1, ... , f_i ????????????j
shakutori = [0] * N

left = N - 1
supplements = set()
#import pdb; pdb.set_trace()
for right in range(N)[::-1]:
    supplements.add(f[right])
    while left > 0  and not(f[left - 1] in supplements):
        supplements.add(f[left - 1])
        left += -1
    shakutori[right] = left
    supplements.remove(f[right])
    if right == left:
        left += -1

dp = [0] * (N+1)
accum = [0] * (N+1)
dp[0] = 1
accum[0] = 0
for i in range(1,N+1):
    accum[i] = (accum[i-1] + dp[i-1])% 1000000007
    dp[i] = (accum[i] - accum[shakutori[i-1]])% 1000000007
print(dp[N])