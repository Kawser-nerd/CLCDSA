import sys
input = sys.stdin.readline 
H, W, K = map(int, input().split())
dp = [[-1]*(W+1) for _ in range(H+1)]


def barcnt(n):
    if n == 0:
        return 1
    elif n == 1:
        return 1
    elif n == 2:
        return 2
    elif n == 3:
        return 3
    elif n == 4:
        return 5
    elif n == 5:
        return 8
    elif n == 6:
        return 13
    elif n == 7:
        return 21
    else:
        return 0
    
def f(H, K):
    if K < 1 or K > W:
        return 0
    else:
        if dp[H][K] != -1:
            return dp[H][K]
        elif H == 1:
            if K == 1:
                dp[H][K] = barcnt(W-1)
                return dp[H][K]
            elif K == 2:
                dp[H][K] = barcnt(W-2)
                return dp[H][K]
            else:
                dp[H][K] = 0
                return 0
        else:
            dp[H][K] = f(H-1, K-1)*barcnt(max(0, K-2))*barcnt(max(0, W-K))
            dp[H][K] += f(H-1, K)*barcnt(max(0, K-1))*barcnt(max(0, W-K))
            dp[H][K] += f(H-1, K+1)*barcnt(max(0, K-1))*barcnt(max(0, W-K-1))
            dp[H][K] %= 10**9+7
            return dp[H][K]

print(f(H, K))