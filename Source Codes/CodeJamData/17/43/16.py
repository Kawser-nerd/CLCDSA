##            
## PROBLEM SOLVING ALGORITHM 
##

def processAlignment(alignment, beams, emptyCells):
    a = list(alignment)

    l = [[] for _ in range(emptyCells)]
    for beam in range(len(beams)):
        _,_,h,v = beams[beam]
        if alignment[beam]!=None:
            if alignment[beam]==False:
                ll = h
            else:
                ll = v
            for item in ll:
                l[item]=True
        else:
            for item in h:
                if l[item]!=True:
                    l[item].append((beam,False))
            for item in v:
                if l[item]!=True:
                    l[item].append((beam,True))

    if l.count(True)==emptyCells:
        return a

    modified = False
    for item in l:
        if item!=True and len(item)==1:
            beam,d = item[0]
            if a[beam]!=None and a[beam]!=d:
                return None
            if a[beam] != d:
                modified = True
                a[beam] = d

    if modified:
        return processAlignment(a, beams, emptyCells)

    for item in l:
        if item!=True and len(item)==2:
            beam,d = item[0]
            a2 = list(a)
            a[beam] = d
            ret = processAlignment(a, beams, emptyCells)
            if ret==None:
                beam,d = item[1]
                a2[beam] = d
                ret = processAlignment(a2, beams, emptyCells)
            return ret

    return None
            



def solve(r,c,grid):
    numbering = [[None for _ in range(c)] for _ in range(r)]

    emptyCells = 0
    for y in range(r):
        for x in range(c):
            if grid[y][x]=='.':
                numbering[y][x] = emptyCells
                emptyCells += 1

    beams = []
    for y in range(r):
        for x in range(c):
            if grid[y][x]=='-' or grid[y][x]=='|':
                h = []
                for dx in range(1,c-x):
                    if grid[y][x+dx]=='#':
                        break
                    if grid[y][x+dx]=='-' or grid[y][x+dx]=='|':
                        h = None
                        break
                    if grid[y][x+dx]=='.':
                        h.append(numbering[y][x+dx])

                if h!=None:
                    for dx in range(1,x+1):
                        if grid[y][x-dx]=='#':
                            break
                        if grid[y][x-dx]=='-' or grid[y][x-dx]=='|':
                            h = None
                            break
                        if grid[y][x-dx]=='.':
                            h.append(numbering[y][x-dx])

                v = []
                for dy in range(1,r-y):
                    if grid[y+dy][x]=='#':
                        break
                    if grid[y+dy][x]=='-' or grid[y+dy][x]=='|':
                        v = None
                        break
                    if grid[y+dy][x]=='.':
                        v.append(numbering[y+dy][x])

                if v!=None:
                    for dy in range(1,y+1):
                        if grid[y-dy][x]=='#':
                            break
                        if grid[y-dy][x]=='-' or grid[y-dy][x]=='|':
                            v = None
                            break
                        if grid[y-dy][x]=='.':
                            v.append(numbering[y-dy][x])
                            
                beams.append((y,x,h,v))


    alignment = [None for _ in range(len(beams))]
    for beam in range(len(beams)):
        _,_,h,v = beams[beam]
        if h==None and v==None:
            return ['IMPOSSIBLE']
        if h==None:
            alignment[beam]=True
        if v==None:
            alignment[beam]=False

    # print("Beams = "+str(beams))
    sol = processAlignment(alignment, beams, emptyCells)
    if sol==None:
        return ['IMPOSSIBLE']

    g = [[grid[y][x] for x in range(c)] for y in range(r)]

    for beam in range(len(beams)):
        y,x,_,_ = beams[beam]
        if sol[beam]:
            g[y][x]='|'
        else:
            g[y][x]='-'

    return ['POSSIBLE'] + ["".join(item) for item in g]

##            
## MAIN LOOP: read(from stdin) - solve - print(to stdout) 
##
for t in range(int(input())):
    
    ## read case
    r,c = [int(item) for item in input().rstrip().split()]
    grid = [input().rstrip() for _ in range(r)]
    
    ## solve and print result
    result = solve(r,c,grid)
    print('Case #'+str(t+1)+': ',end='')
    for item in result:
        print(item)
    
