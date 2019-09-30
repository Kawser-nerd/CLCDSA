import sys
from graph import *

T = int(sys.stdin.readline())

for i in range(T):
    R,C = map(int, sys.stdin.readline().strip().split())
    ps = map(int, sys.stdin.readline().strip().split())
    horiz = {}
    vert = {}
    locOut = {}
    for j in range(R+1):
        for k in range(C+1):
            if (k < C):
                horiz[(j,k)] = Node("h%d%d"%(j,k), [])
                horiz[(j,k)].locs = []
            if (j < R):
                vert[(j,k)] = Node("v%d%d"%(j,k), [])
                vert[(j,k)].locs = []
    for j in range(R+1):
        for k in range(C+1):
            if (k < C):
                n = horiz[(j,k)]
                if (j > 0):
                    n.children.append(vert[(j-1,k)])
                    n.locs.append(((j-1,k),"\\"))
                    n.children.append(vert[(j-1,k+1)])
                    n.locs.append(((j-1,k),"/"))
                if (j < R):
                    n.children.append(vert[(j,k)])
                    n.locs.append(((j,k),"/"))
                    n.children.append(vert[(j,k+1)])
                    n.locs.append(((j,k),"\\"))
            if (j < R):
                n2 = vert[(j,k)]
                if (k > 0):
                    n2.children.append(horiz[(j,k-1)])
                    n2.locs.append(((j,k-1),"\\"))
                    n2.children.append(horiz[(j+1,k-1)])
                    n2.locs.append(((j,k-1),"/"))
                if (k < C):
                    n2.children.append(horiz[(j,k)])
                    n2.locs.append(((j,k),"/"))
                    n2.children.append(horiz[(j+1,k)])
                    n2.locs.append(((j,k),"\\"))
    # print "Horiz"
    # for h in horiz:
    #     print horiz[h].name, horiz[h].children
    # print "Vert"
    # for v in vert:
    #     print vert[v].name, vert[v].children
    pps = []
    for l in range(len(ps)/2):
        pps.append((ps[2*l], ps[2*l+1]))

    def getNode(num):
        if (num <= C):
            return horiz[(0,num-1)]
        elif (num <= (C+R)):
            return vert[(num-C-1,C)]
        elif (num <= (2*C+R)):
            return horiz[(R,C-(num-C-R))]
        else:
            return vert[(R-(num-2*C-R),0)]

    # Sort pairs by edge dist
    def edgeDist(pp):
        return min((pp[0]-pp[1])%(2*(R+C)), (pp[1]-pp[0])%(2*(R+C)))
    pps.sort(key=edgeDist)

    grid = {}
    possible = True

    def printGrid(final=True):
        for j in range(R):
            for k in range(C):
                if (j,k) in grid:
                    sys.stdout.write(grid[(j,k)])
                elif final:
                    sys.stdout.write("/")
                else:
                    sys.stdout.write(".")
            print
    
    for pp in pps:
        src = getNode(pp[0])
        targetName = getNode(pp[1]).name
        # print "Bfs:",src,targetName
        def checkEnd(x):
            # print "Check end:",x,targetName,(x.name == targetName)
            return (x.name == targetName)
        path = bfs(src, checkEnd)
        # print pp,path
        if path is None:
            possible = False
            break
        last = path[0]
        last.skip = True
        for n in path[1:]:
            n.skip = True
            index = last.children.index(n)
            loc,sym = last.locs[index]
            if loc in grid:
                if (grid[loc] != sym):
                    possible = False
                    break
            else:
                grid[loc] = sym
            # DEBUG
            # printGrid()
            last = n
        if not possible:
            break    
        # printGrid()
        
    if not possible:
        print "Case #%d:"%(i+1)
        print "IMPOSSIBLE"
    else:
        print "Case #%d:"%(i+1)
        printGrid(True)
        
