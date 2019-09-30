infilecode = "DLI"

import sys
mapping = {"A":"A", "B":"B", "C":"C", "D":"D", "E":"E", "X":"example", "S":"-small", "L":"-large", "P":"-practice", "0":"-attempt0", "1":"-attempt1", "2":"-attempt2", "z":"-1", "Z":"-2", "I":".in", "T":".txt"}
infile = "".join(mapping[c] for c in infilecode)
outfile = infile.replace(".in", "") + ".out.txt"
sys.stdin = open(infile, 'r')
output = open(outfile, 'w')

T = int(input())


def manhattan(a,n):
    return max(abs(a[0]-n), abs(a[1]-n))

def manhattandiag(a,n):
    return abs(a[0]-n) + abs(a[1]-n)


for case in range(1,T+1):
    
    N, M = map(int,input().split())
    print(N,M)
    n = (N-1)/2

    order = [x[2] for x in sorted([ (-manhattan([b,c],n), -manhattandiag([b,c],n), (b,c) )  for b in range(N) for c in range(N) ]) ]

    #print("order = ", order)


    grid = [["."]*N for i in range(N)]
    bishops = []
    rooks = []
    rookrow = list(range(N))  
    rookcol = list(range(N))  
    style = 0

    for i in range(M):
        z, r, c = input().split()
        r = int(r)-1
        c = int(c)-1
        grid[r][c] = z
        if z in "+o":
            bishops += [(r,c)]
            order = [ o for o in order if not (o[0]+o[1] == r+c or o[0]-o[1] == r-c)]
        if z in "xo":
            rooks += [(r,c)]
            rookrow = [ff for ff in rookrow if ff != r]
            rookcol = [ff for ff in rookcol if ff != c]
        if z in "+x":
            style += 1
        if z == "o":
            style += 2


    #print("order after input = ", order)

    addbishops = []
    while order:
        xx = order.pop(0)
        addbishops += [xx]
        order = [ o for o in order if not (o[0]+o[1] == xx[0]+xx[1] or o[0]-o[1] == xx[0]-xx[1])]
        #order = [ o for o in order if not (o[0]+xx[0] == o[1]+xx[1] or o[0]-xx[0] == o[1]-xx[1])]


    addrooks = []
    for g,h in zip(rookrow, rookcol):
        addrooks += [(g,h)]

    #print(*grid, sep="\n")
    #print(bishops)
    #print(rooks)


    #print("addbishops = ", addbishops)
    #print("addrooks = ", addrooks)

    answer = []

    for pp,qq in addbishops:
        if (pp,qq) in addrooks:
            answer += ["o " + str(pp+1) + " " + str(qq+1)]
            style += 2
            addrooks = list(set(addrooks)-{(pp,qq)})
        elif grid[pp][qq] == "x":
            answer += ["o " + str(pp+1) + " " + str(qq+1)]
            style += 1
        else:
            answer += ["+ " + str(pp+1) + " " + str(qq+1)]
            style += 1

    for pp,qq in addrooks:
        if grid[pp][qq] == "+":
            answer += ["o " + str(pp+1) + " " + str(qq+1)]
            style += 1
        else:
            answer += ["x " + str(pp+1) + " " + str(qq+1)]
            style += 1



    


    
    
    
    print("Case #%d:" % case, style, len(answer))
    print("Case #%d:" % case, style, len(answer), file = output)

    if answer:
        print(*answer, sep="\n")
        print(*answer, sep="\n", file = output)
