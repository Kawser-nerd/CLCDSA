
def solve2sat(cl, vv):
    while True:
        for (r1, r2) in list(cl):
            a1, b1 = r1
            a2, b2 = r2
            if a1 in vv:
                if bool(b1) == bool(vv[a1]):
                    cl.discard((r1, r2))
                else:
                    if a2 in vv:
                        if bool(vv[a2]) != bool(b2):
                            return False, None
                    else:
                        vv[a2] = b2
                    cl.discard((r1, r2))
            if a2 in vv:
                if bool(b2) == bool(vv[a2]):
                    cl.discard((r1, r2))
                else:
                    vv[a1] = b1
                    cl.discard((r1, r2))
        if len(cl) == 0:
            return True, vv
        u = list(cl)[0][0]
        if u[0] in vv: continue
        vv[u[0]] = 0

def solve():
    r, c = map(int, input().split())
    data = []
    for _ in range(r):
        data.append(input().strip())
    dest = [[[None] * 4 for _ in range(c)] for _ in range(r)]
    DIR = [(0, 1), (1, 0), (0, -1), (-1, 0)]
    for i in range(r):
        for j in range(c):
            for d in range(4):
                if dest[i][j][d] != None:
                    continue
                stack = [(i,j,d)]
                ni, nj, nd = i, j, d
                while True:
                    ni, nj = ni + DIR[nd][0], nj + DIR[nd][1]
                    if not (0 <= ni < r and 0 <= nj < c):
                        result = (ni, nj, nd)
                        break
                    u = data[ni][nj]
                    if u in "#|-":
                        result = (ni, nj, nd)
                        break
                    #print(u)
                    if u == "/":
                        nd = [3,2,1,0][nd]
                    elif u == "\\":
                        nd = [1,0,3,2][nd]
                    if dest[ni][nj][nd] != None:
                        result = dest[ni][nj][nd]
                        break
                    stack.append((ni, nj, nd))
                for (ii, jj, dd) in stack:
                    dest[ii][jj][dd] = result
                #print(stack, result)
                #if i == 1 and j == 2:
                #    print(stack, dest)
    #print(dest)
    #for i in range(r):
    #    for j in range(c):
    #        print(dest[i][j], end = "    ")
    #    print("")
    def get(i, j, d):
        ni, nj, nd = dest[i][j][d]
        if not (0 <= ni < r and 0 <= nj < c):
            return None
        elif data[ni][nj] not in "-|":
            return None
        return (ni, nj, nd)
    cl = set()
    force = []
    for i in range(r):
        for j in range(c):
            if data[i][j] in "-|":
                if (get(i,j,0) or get(i,j,2)) and (get(i,j,1) or get(i,j,3)):
                    #print(i,j)
                    return False, None
                if get(i, j, 0) or get(i, j, 2):
                    force.append(((i, j), 1))
                if get(i, j, 1) or get(i, j, 3):
                    force.append(((i, j), 0))
            elif data[i][j] == ".":
                hr1 = get(i, j, 0)
                hr2 = get(i, j, 2)
                ve1 = get(i, j, 1)
                ve2 = get(i, j, 3)
                okay = []
                if hr1 and hr2:
                    pass
                elif hr1:
                    okay.append(hr1)
                elif hr2:
                    okay.append(hr2)
                if ve1 and ve2:
                    pass
                elif ve1:
                    okay.append(ve1)
                elif ve2:
                    okay.append(ve2)
                if len(okay) == 0:
                    #print(dest[i][j])
                    #print(i,j)
                    return False, None
                elif len(okay) == 1:
                    ni, nj, nd = okay[0]
                    force.append(((ni,nj), nd%2))
                else:
                    ni1, nj1, nd1 = okay[0]
                    ni2, nj2, nd2 = okay[1]
                    u1 = ((ni1,nj1),nd1%2)
                    u2 = ((ni2,nj2),nd2%2)
                    cl.add(tuple(sorted([u1,u2])))
    #print(cl)
    vt = set([u for (u, b) in force if b])
    vf = set([u for (u, b) in force if not b])
    if len(vt.intersection(vf)) > 0:
        return False, None
    vv = {u:b for (u,b) in force}
    rr, vv = solve2sat(cl, vv)
    if not rr:
        return False, None
    ndata = [list(z) for z in data]
    for (i, j) in vv:
        if vv[(i, j)]:
            ndata[i][j] = "|"
        else:
            ndata[i][j] = "-"
    res = "\n".join("".join(z) for z in ndata)
    return True, res


t = int(input())
for tc in range(t):
    print("Case #%d:" % (tc+1), end =" ")
    ok, sol = solve()
    if ok:
        print("POSSIBLE")
        print(sol)
    else:
        print("IMPOSSIBLE")
