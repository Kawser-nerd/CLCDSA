inp = open("d:\\incoming\\b-small-attempt1.in", "r")
#inp = open("d:\\incoming\\b.in", "r")
outp = open(".\\b-1.out", "w")

global board, cache, r, c, f, row
    

def fall(x, nextrows):
    ret = 0
    while ret < len(nextrows) and (nextrows[ret] & (2**x)) == 0:
        ret += 1
    return ret

T = int(inp.readline())
for cc in range(T):
    r, c, f = map(int, inp.readline().split())

    sol = "meh"
    board = []
    row = [0] * r
    row.append((2**c)-1)
    for i in range(r):
        board.append(inp.readline().strip())
        for j in range(c):
            if board[i][j] == "#":
                row[i] += (2 ** j)


    dic = {}
    q = []
    q.append((0, 0, row[0], row[1]))
    dic[q[0]] = 0
    ret = 99999
    while len(q) > 0:
        here = q.pop()
        y, x, thisrow, nextrow = here
        #print "(%d,%d) this (%d) next (%d) => %d" % (y, x, thisrow, nextrow, dic[here])
        if y == r-1:
            ret = min(ret, dic[here])
        
        delta = [-1, 1]
        for d in delta:
            if 0 <= x+d and x+d <= c-1 and (thisrow & (2**(x+d))) == 0:
                # move left/right
                dist = fall(x+d, [nextrow] + row[y+2:])
                if dist > f: continue
                nxt = None
                if dist == 0:
                    nxt = (y, x+d, thisrow, nextrow)
                elif dist == 1:
                    nxt = (y+1, x+d, nextrow, row[y+2])
                else:
                    nxt = (y+dist, x+d, row[y+dist], row[y+dist+1])
                if nxt not in dic or dic[nxt] > dic[here]:
                    dic[nxt] = dic[here]
                    q.append(nxt)
                # dig left/right
                if y+1 < r and (nextrow & (2**(x+d))) > 0:
                    nxt = (y, x, thisrow, nextrow - (2**(x+d)))
                    if nxt not in dic or dic[nxt] > dic[here] + 1:
                        dic[nxt] = dic[here] + 1
                        q.append(nxt)
                
    if ret >= 99999:
        sol = "No"
    else:
        sol = "Yes %d" % ret
    
    outp.write("Case #%d: %s\n" % (cc+1, sol))
    print "Case #%d: %s" % (cc+1, sol)
    

outp.close()
