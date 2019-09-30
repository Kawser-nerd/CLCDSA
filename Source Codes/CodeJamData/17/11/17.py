T = input()
for t in range(T):
    R,C = map(int, raw_input().split())
    B = [list(raw_input()) for _ in range(R)]

    for r in range(R):
        x = ""
        for c in range(C):
            if B[r][c]!="?":
                x = B[r][c]
                break
        if x != "":
            for c in range(C):
                if B[r][c]=="?":
                    B[r][c] = x
                else:
                    x = B[r][c]
    x = -1
    for r in range(R):
        if B[r][0] != "?":
            x = r
            break
    for r in range(R):
        if B[r][0] == "?":
            for c in range(C):
                B[r][c] = B[x][c]
        else:
            x = r
    print "Case #%s:" % (t+1)
    for r in range(R):
        print "".join(B[r])
