'''
Created on Sep 1, 2009

Codejam template

@author: Dan
'''

filepath = ''
#filepath = 'C:\Users\Dan\Downloads\'

fileprefix = 'B-large' #Change me!


filepathname = filepath + fileprefix
infilename = filepathname + '.in'
outfilename = filepathname + '.out'
lines = open(infilename, 'rU').read().split("\n")
outfile = open(outfilename, 'w+')

cases = int(lines[0])
linenum = 1

def solve1(emap, smap, i, j, h, w, nextbasinlist):
    if smap[i][j] != -1:
        return
    
    alt = emap[i][j]
    #N, W, E, S
    low = alt
    next = (0,0)
    if i != 0:
        alto = emap[i-1][j]
        if alto < low:
            low = alto
            next = (-1,0)
    if j != 0:
        alto = emap[i][j-1]
        if alto < low:
            low = alto
            next = (0,-1)
            
    if j != w-1:
        alto = emap[i][j+1]
        if alto < low:
            low = alto
            next = (0,1)
    
    if i != h-1:
        alto = emap[i+1][j]
        if alto < low:
            low = alto
            next = (1,0)
    
    if next==(0,0):
        #basin
        smap[i][j] = nextbasinlist[0]
        nextbasinlist[0] += 1
    
    else:
        #not basin
        solve1(emap, smap, i+next[0], j+next[1], h, w, nextbasinlist)
        smap[i][j] = smap[i+next[0]][j+next[1]]

def solve(emap, h, w):
    smap = [[-1 for i in range(w)] for j in range(h)]
    nextbasinlist = [0]
#    print (emap)
#    print (smap)
    for i in range(h):
        for j in range(w):
            solve1(emap, smap, i, j, h, w, nextbasinlist)
    
    rmap = [['?' for i in range(w)] for j in range(h)]
    labels = {}
    alllabels = 'abcdefghijklmnopqrstuvwxyz'
    clabel = 0
    for i in range(h):
        for j in range(w):
            if smap[i][j] not in labels:
                labels[smap[i][j]] = alllabels[clabel]
                clabel += 1
            rmap[i][j] = labels[smap[i][j]]
    
    rstr = ""
    for row in rmap:
        rstr += "\n"
        rstr += " ".join(row)
        
    
    return rstr

for casenum in range(1, cases+1):
    #Begin parsing for one problem starting at line linenum
    h,w = [int(x) for x in lines[linenum].split(' ')]
    linenum += 1
    emap = []
    for i in range(h):
        emap.append([int(x) for x in lines[linenum].split(' ')])
        linenum+=1
    out = solve(emap, h, w) #Assign solved value
    #End parsing
    casestr = 'Case #'+str(casenum)+': '+str(out)
    print (casestr)
    outfile.write(casestr+"\n")