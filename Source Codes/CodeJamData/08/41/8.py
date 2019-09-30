def min_changes(index, des, M, tree):
    if(isLeaf(index, M)):
        if(des != tree[index]):
            return -1
        else:
            return 0
    res = -1
    cres = -1
    if(tree[index][1] == 1):
        if(tree[index][0] == 0): #CHANGE TO AND
            if(des == 1):
                l = min_changes(2*index, 1, M, tree)
                r = min_changes(2*index + 1, 1, M, tree)
                if(l != -1 and r != -1):
                    cres =  l + r
                else:
                    cres =  -1
            else:
                l = min_changes(2*index, 0, M, tree)
                r = min_changes(2*index + 1, 0, M, tree)
                if(l != -1 and r != -1):
                    cres =  min(l, r)
                elif(l != -1):
                    cres =  l
                elif(r != -1):
                    cres =  r
                else:
                    cres =  -1
        else: #CHANGE TO OR
            if(des == 0):
                l = min_changes(2*index, 0, M, tree)
                r = min_changes(2*index + 1, 0, M, tree)
                if(l != -1 and r != -1):
                    cres =  l + r
                else:
                    cres =  -1
            else:
                l = min_changes(2*index, 1, M, tree)
                r = min_changes(2*index + 1, 1, M, tree)
                if(l != -1 and r != -1):
                    cres =  min(l, r)
                elif(l != -1):
                    cres =  l
                elif(r != -1):
                    cres =  r
                else:
                    cres =  -1

    if(tree[index][0] == 1): #AND
        if(des == 1):
            l = min_changes(2*index, 1, M, tree)
            r = min_changes(2*index + 1, 1, M, tree)
            if(l != -1 and r != -1):
                res =  l + r
            else:
                res =  -1
        else:
            l = min_changes(2*index, 0, M, tree)
            r = min_changes(2*index + 1, 0, M, tree)
            if(l != -1 and r != -1):
                res =  min(l, r)
            elif(l != -1):
                res =  l
            elif(r != -1):
                res =  r
            else:
                res =  -1
    else: #OR
        if(des == 0):
            l = min_changes(2*index, 0, M, tree)
            r = min_changes(2*index + 1, 0, M, tree)
            if(l != -1 and r != -1):
                res =  l + r
            else:
                res =  -1
        else:
            l = min_changes(2*index, 1, M, tree)
            r = min_changes(2*index + 1, 1, M, tree)
            if(l != -1 and r != -1):
                res =  min(l, r)
            elif(l != -1):
                res =  l
            elif(r != -1):
                res =  r
            else:
                res =  -1
    if(res != -1 and cres != -1):
        #print 'index: %d 1 %d %d' % (index, cres, res)
        return min(cres + 1, res)
    elif(res != -1):
        #print 'index: %d 2 %d %d' % (index, cres, res)
        return res
    elif(cres != -1):
        #print 'index: %d 3 %d %d' % (index, cres, res)
        return cres + 1
    else:
        #print 'index: %d 4 %d %d' % (index, cres, res)
        return -1

def isLeaf(i, M):
    return (i > (M - 1)/2)

filename = "A-large.in"
f = open(filename, 'r')
of = open("A-large.out", 'w')

N = int(f.readline())

for x in xrange(N):
    l = f.readline().split(' ')
    M = int(l[0])
    V = int(l[1])
    nodes = [-1]
    for y in xrange((M - 1)/2):
        l = f.readline().split(' ')
        nodes.append((int(l[0]), int(l[1])))
    for y in xrange((M + 1)/2):
        l = f.readline()
        nodes.append(int(l))
    #print nodes
    r = min_changes(1, V, M, nodes)
    if(r == -1):
        print >> of, "Case #%d: IMPOSSIBLE" % (x + 1)
    else:
        print >> of, "Case #%d: %d" % (x + 1, r)



