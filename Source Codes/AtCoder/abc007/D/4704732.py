A, B = map(int, input().split())

def f(n):
    digit = len(str(n))
    dp = [[0] * 2 for _ in range(digit+1)]
    dp[0][0] = 1
    for d in range(digit):
        for i in range(2):
            if i == 1:
                t = 9
            else:
                t = int(str(n)[d])

            for j in range(t+1):
                if j != 4 and j != 9:
                    dp[d+1][i or j < t] += dp[d][i]

    return n - dp[digit][0] - dp[digit][1]


print(f(B)-f(A-1))