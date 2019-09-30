N, K = map(int, input().split())
S = [1 if c=="1" else -1 if c=="0" else 0 for c in input()]
mod = 10**9+7

next_dp = [[0]*(K+2) for _ in [0]*(K+2)]
next_dp[0][0] = 1

prev_index = tuple([0]+list(range(K)))

for i, n in enumerate(S, start=1):
    dp, next_dp = next_dp, [[0]*(K+2) for _ in [0]*(K+2)]
    for one_prev, one_count, one_next in zip(prev_index, range(min(i, K+1)), range(1, min(i, K+1)+1)):
        minus, plus = next_dp[one_prev], next_dp[one_next]

        if n > 0:
            for zero_next, zero_prev, value in zip(range(1, min(i, K-one_count+1)+1), prev_index, dp[one_count]):
                plus[zero_prev] += value
        elif n < 0:
            for zero_next, value in zip(range(1, min(i, K-one_count+1)+1), dp[one_count]):
                minus[zero_next] += value
        else:
            for zero_next, zero_prev, value in zip(range(1, min(i, K-one_count+1)+1), prev_index, dp[one_count]):
                plus[zero_prev] += value
                minus[zero_next] += value

print(sum(sum(next_dp[i][:K-i+1])for i in range(K+1)) % mod)