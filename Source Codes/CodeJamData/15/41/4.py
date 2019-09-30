tnum = int(raw_input())
for tcou in range(tnum):
    n, m = [int(x) for x in raw_input().split()]
    t = [raw_input().strip() for _ in range(n)]
    def can(r, c):
        if t[r][:c]+t[r][c+1:]!='.'*(m-1):
            return True
        if ''.join(t[i][c] for i in range(n) if i!=r)!='.'*(n-1):
            return True
        return False
    good = True
    ans = 0
    for r in range(n):
        for c in range(m):
            if t[r][c]!='.':
                if t[r][c]=='<':
                    if not can(r, c):
                        good = False
                    ans += 1
                break
    for r in range(n):
        for c in range(m-1, -1, -1):
            if t[r][c]!='.':
                if t[r][c]=='>':
                    if not can(r, c):
                        good = False
                    ans += 1
                break
    for c in range(m):
        for r in range(n):
            if t[r][c]!='.':
                if t[r][c]=='^':
                    if not can(r, c):
                        good = False
                    ans += 1
                break
    for c in range(m):
        for r in range(n-1, -1, -1):
            if t[r][c]!='.':
                if t[r][c]=='v':
                    if not can(r, c):
                        good = False
                    ans += 1
                break
    print "Case #{}: {}".format(tcou+1, ans if good else 'IMPOSSIBLE')
