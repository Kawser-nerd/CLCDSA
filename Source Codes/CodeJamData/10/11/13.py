
def Solution():
    N, K = map(int, raw_input().split())
    B = []
    for r in xrange(N):
        row = ""
        for p in raw_input():
            if p != ".":
                row += p
        B.append(row.rjust(N, "."))
    win = set()
    for r in xrange(N):
        for c in xrange(N):
            p = B[r][c]
            if p == ".":
                continue
            for dr, dc in [(1,0),(0,1),(1,1),(1,-1)]:
                r1, c1 = r, c
                count = K-1
                while count:
                    r1 += dr
                    c1 += dc
                    if r1 == N or c1 == N or c1 == -1 or B[r1][c1] != p:
                        break
                    count -= 1
                if count == 0:
                    win.add(p)
    if len(win) == 0:
        print "Neither"
    elif len(win) == 2:
        print "Both"
    elif "R" in win:
        print "Red"
    else:
        print "Blue"

#---------------------------------------------------------------

T = int(raw_input())
for testcase in xrange(T):
    print "Case #%d:" % (testcase+1),
    Solution()
