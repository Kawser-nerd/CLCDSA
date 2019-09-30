from itertools import accumulate
N, K = map(int, input().split())
a = [int(input()) for _ in [0]*N]

if sum(a) == K or K == 0:
    print(int(K > 0))
    exit()

inf, acc = float("inf"), tuple(accumulate(a))
dp = [inf]*(N+1)
dp[1] = 1

for i, (p_game, c_game) in enumerate(zip(acc, acc[1:]), start=2):
    for j, win in zip(range(i+1, 0, -1), dp[i::-1]):
        req = (c_game * win) // p_game + 1
        if req <= K and req <= c_game:
            dp[j] = min(dp[j], req)

for i, n in zip(range(N, 0, -1), dp[::-1]):
    if n < inf:
        print(i)
        break