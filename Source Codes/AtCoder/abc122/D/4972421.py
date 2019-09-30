import sys

s2nn = lambda s: [int(c) for c in s.split(' ')]

ss2nn = lambda ss: [int(s) for s in list(ss)]
ss2nnn = lambda ss: [s2nn(s) for s in list(ss)]

i2s = lambda: sys.stdin.readline().rstrip()
i2n = lambda: int(i2s())
i2nn = lambda: s2nn(i2s())

ii2ss = lambda n: [sys.stdin.readline() for _ in range(n)]

# NG: 021, 201, 012, 0x21, 02x1
def check(c0, c1, c2, c3):
    if c0 == 1 and c1 == 2 and c2 == 0:
        return False
    if c0 == 1 and c1 == 0 and c2 == 2:
        return False
    if c0 == 2 and c1 == 1 and c2 == 0:
        return False
    if c0 == 1 and c1 == 2 and c3 == 0:
        return False
    if c0 == 1 and c2 == 2 and c3 == 0:
        return False
    return True

def main(N):
    mod = int(1e+9) + 7
    
    dp1 = [0 for _ in range(4)]
    for c0 in range(4):
        if check(c0, -1, -1, -1) == False:
            continue
        dp1[c0] = 1
    if N == 1:
        ans = 0
        for c1 in range(4):
            ans += dp1[c1]
            ans %= mod
        print(ans)
        return
    
    dp2 = [[0 for _ in range(4)] for _ in range(4)]
    for c1 in range(4):
        for c0 in range(4):
            if check(c0, c1, -1, -1) == False:
                continue
            dp2[c0][c1] += dp1[c1]
            dp2[c0][c1] %= mod
    if N == 2:
        ans = 0
        for c1 in range(4):
            for c2 in range(4):
                ans += dp2[c1][c2]
                ans %= mod
        print(ans)
        return
    
    dp3 = [[[0 for _ in range(4)] for _ in range(4)] for _ in range(4)]
    for c1 in range(4):
        for c2 in range(4):
            for c0 in range(4):
                if check(c0, c1, c2, -1) == False:
                    continue
                dp3[c0][c1][c2] += dp2[c1][c2]
                dp3[c0][c1][c2] %= mod
    if N == 3:
        ans = 0
        for c1 in range(4):
            for c2 in range(4):
                for c3 in range(4):
                    ans += dp3[c1][c2][c3]
                    ans %= mod
        print(ans)
        return
    
    dp = [[[[0 for _ in range(4)] for _ in range(4)] for _ in range(4)] for _ in range(N+1)]
    for c1 in range(4):
        for c2 in range(4):
            for c3 in range(4):
                dp[3][c1][c2][c3] = dp3[c1][c2][c3]
    
    for l in range(3, N):
        for c1 in range(4):
            for c2 in range(4):
                for c3 in range(4):
                    for c0 in range(4):
                        if check(c0, c1, c2, c3) == False:
                            continue
                        dp[l+1][c0][c1][c2] += dp[l][c1][c2][c3]
                        dp[l+1][c0][c1][c2] %= mod
    ans = 0
    for c1 in range(4):
        for c2 in range(4):
            for c3 in range(4):
                ans += dp[N][c1][c2][c3]
                ans %= mod
    print(ans)

main(i2n())