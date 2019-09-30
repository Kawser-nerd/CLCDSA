def adj(drum,i0,j0):
    #print '        adj',i0,j0
    for di,dj in [(0,-1),(0,1),(1,0),(-1,0)]:
        i,j = i0+di,j0+dj
        if i < 0 or i >= len(drum): continue
        j = (j + len(drum[0])) % len(drum[0])
        yield (i,j)

def ok(drum,i0,j0):
    #print '    ok',i0,j0
    if drum[i0][j0] == None:
        return True
    low = 0
    high = 0
    for i,j in adj(drum,i0,j0):
        if drum[i][j] == None:
            high += 1
        if drum[i][j] == drum[i0][j0]:
            low += 1
            high += 1
        if low > drum[i0][j0]:
            return False
    return low <= drum[i0][j0] <= high
        

def canonize(drum):
    strs = []
    for j0 in range(len(drum[0])):
        ss = []
        for i in range(len(drum)):
            for j in range(len(drum[0])):
                ss.append(str(drum[i][(j+j0)%len(drum[0])]))
            ss.append('\n')
        strs.append(''.join(ss))
    return min(strs)
        
def solve(r,c,drum=None,i=0,j=0,acc=None):
    #print 'solve',i,j
    if drum == None:
        drum = [[None]*c for _ in range(r)]
        acc = set()
    if i >= len(drum):
        #print '-----'
        #for line in drum:
        #    print ' '.join(map(str,line))
        #print canonize(drum)
        acc.add(canonize(drum))
        return len(acc)
    
    for d in range(1,3+1):
        drum[i][j] = d
        good = True
        if not ok(drum,i,j):
            good = False
        if good:
            for i1,j1 in adj(drum,i,j):
                if not ok(drum,i1,j1):
                    good = False
                    break
        if not good:
            #print 'BAD:'
            #for line in drum:
            #    print ' '.join(map(str,line))
            continue
        
        j1 = j+1
        i1 = i
        if j1 >= len(drum[0]):
            j1 = 0
            i1 += 1
        solve(r,c,drum,i1,j1,acc)
        
    drum[i][j] = None
    # print acc
    return len(acc)
                

n_cases = input()
for case in range(1,n_cases + 1):
    r,c = map(int,raw_input().split(' '))
    
    solution = solve(r,c)
    print "Case #%d: %s" % (case,solution)