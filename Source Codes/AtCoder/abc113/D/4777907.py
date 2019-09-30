def valid(x):
    even_mask = 85  # 01010101
    odd_mask = 170  # 10101010
    return (x & odd_mask) >> 1 & (x & even_mask) == 0 and (x & odd_mask) << 1 & (x & even_mask) == 0

def yoko(x):
    a, b, c = 0, 0, 0
    for bit in range(1<<(W-1)):
        if not valid(bit):
            continue
        if bit >> (W - x - 1) & 1:
            a += 1
        elif W - x - 2 >= 0 and bit >> (W - x - 2) & 1:
            c += 1
        else:
            b += 1
    return a, b, c

H, W, K = map(int, input().split())

dp = [[0] * W for _ in range(H+1)]
dp[0][0] = 1
BIG = 1000000007

for i in range(H):
    for j in range(W):
        a, b, c = yoko(j)
        if j - 1 >= 0:
            dp[i+1][j-1] += a * dp[i][j]
            dp[i+1][j-1] %= BIG
        dp[i+1][j] += b * dp[i][j]
        dp[i+1][j] %= BIG
        if j + 1 < W:
            dp[i+1][j+1] += c * dp[i][j]
            dp[i+1][j+1] %= BIG
print(dp[H][K-1])