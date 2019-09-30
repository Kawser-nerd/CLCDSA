# -*-cofing:utf-8-*-
field = [[] for _ in range(19)]
bs = []
ws = []
for i in range(19):
    row = input()
    for j,r in enumerate(row):
        field[i].append(r)
        if r == "x":
            ws.append([i,j])
        elif r == "o":
            bs.append([i,j])

vector = [[-1,1],[0,1],[1,1],[1,0]]

def is_error(bs,ws,field):
    def search(stones,s,v,count = 0):
        nx = s[0]+v[0]
        ny = s[1]+v[1]
        if 0<=nx<=18 and 0<=ny<=18:
            if [nx,ny] in stones:
                count += 1
                return search(stones,[nx,ny],v,count)
            else:
                return count
        else:
            return count

    def is_won(stones):
        max_count = 0
        for v in vector:
            count = 0
            for s in stones:
                count = search(stones,s,v)
                if count>= 4:
                    return True
        return False
    r = False
    dif = (len(bs) - len(ws))
    bwon = is_won(bs)
    wwon = is_won(ws)
    if not dif in [0,1]:
        r = True
    else:
        if bwon and wwon:
            r = True
        elif bwon:
            if dif == 0:
                r = True
            else:
                r = True
                for s in bs:
                    tmps = [i for i in bs if i not in [s]]
                    if not is_won(tmps):
                        r = False
                        break
        elif wwon:
            if dif == 1:
                r = True
            else:
                r = True
                for s in ws:
                    tmps = [i for i in ws if i not in [s]]
                    if not is_won(tmps):
                        r = False
                        break
    return r

if is_error(bs,ws,field):
    print("NO")
else:
    print("YES")