def check(R,C,W,B):
    c = sum(b.count(1) for b in B)
    for y in range(R):
        for x in range(C-W+1):
            if B[y][x:x+W].count(1)==c and B[y][x:x+W].count(-1)==0:
                return True
    return False

def BT(R,C,W,B):
    Bt = tuple(tuple(b) for b in B)
    if Bt in memo:
        return memo[Bt]

    ans = 9999
    for y in range(R):
        for x in range(C):
            if B[y][x]==0:
                ans2 = 0

                B[y][x] = 1
                if check(R,C,W,B):
                    if sum(b.count(1) for b in B)==W:
                        ans2 = max(ans2, 1)
                    else:
                        ans2 = max(ans2, BT(R,C,W,B)+1)
                B[y][x] = 0
                
                B[y][x] = -1
                if check(R,C,W,B):
                    ans2 = max(ans2, BT(R,C,W,B)+1)
                B[y][x] = 0

                ans = min(ans, ans2)

    memo[Bt] = ans
    return ans

def solve(R,C,W):
    global memo
    B = [[0]*C for _ in range(R)]
    memo = {}
    return BT(R,C,W,B)

for t in range(input()):
    R,C,W = map(int, raw_input().split())
    print "Case #%s: %s"%(t+1, solve(R,C,W))
