import sys

filepath = ''
fileprefix = sys.argv[1] #Change me!

filepathname = filepath + fileprefix
infilename = filepathname + '.in'
outfilename = filepathname + '.out'
lines = open(infilename, 'rU').read().split("\n")
outfile = open(outfilename, 'w+')

linenum = 1
cases = int(lines[0])
from math import floor,sqrt
from fractions import gcd
def triedge(c,a):
    return int(floor(sqrt(pow(c,2)-pow(a,2))))
def imgsrch(hom, H, W, D, step_h, step_v, posx, posy, dx, dy):
    x=0
    y=0
    while pow(x,2)+pow(y,2)<pow(D,2):
        if (x+0.5)*step_v<(y+0.5)*step_h:
            posx+=dx
            x+=1
            if hom[posx][posy]=='#':
                dx=-dx
                posx+=dx

        elif (x+0.5)*step_v>(y+0.5)*step_h:
            posy+=dy
            y+=1
            if hom[posx][posy]=='#':
                dy=-dy 
                posy+=dy
        else:
            x+=1
            y+=1
            posx+=dx
            posy+=dy
            if hom[posx][posy]=='#':
                if hom[posx-dx][posy]=='#' and hom[posx][posy-dy]=='#':
                    dx=-dx
                    dy=-dy
                    posx+=dx
                    posy+=dy
                elif hom[posx-dx][posy]=='#':
                    dy=-dy
                    posy+=dy
                elif hom[posx][posy-dy]=='#':
                    dx=-dx
                    posx+=dx
                else: return 0
        if hom[posx][posy]=='X' and y*step_h==x*step_v and pow(x,2)+pow(y,2)<=pow(D,2):
            return 1
    return 0
def linesrch(hom, H, W, D, posx, posy, dx, dy):
    if posx<0 or posy<0: return 0
    for i in xrange(1,D+1):
        posx+=dx
        posy+=dy
        if hom[posx][posy]=='#':
            dx=-dx
            dy=-dy
            posx+=dx
            posy+=dy
        if hom[posx][posy]=='X':
            return 1
    return 0
def solve(hom, H, W, D):
    count=0
    posx=-1
    posy=-1
    for i in xrange(0,H):
        if posx!=-1: break
        for j in xrange(0,W):
            if hom[i][j]=='X': 
                posx=i
                posy=j
                break
    mylist=[]
    for step_h in xrange(1,D):
        for step_v in xrange(1,triedge(D,step_h)+1):
            g=gcd(step_h, step_v)
            if (step_h/g, step_v/g) in mylist: continue
            mylist.append((step_h/g, step_v/g))
            count+=imgsrch(hom, H, W, D, step_h, step_v, posx, posy, 1, 1)
            count+=imgsrch(hom, H, W, D, step_h, step_v, posx, posy, 1, -1)
            count+=imgsrch(hom, H, W, D, step_h, step_v, posx, posy, -1, 1)
            count+=imgsrch(hom, H, W, D, step_h, step_v, posx, posy, -1, -1)
    count+=linesrch(hom, H, W, D, posx, posy, 1, 0)
    count+=linesrch(hom, H, W, D, posx, posy, 0, 1)
    count+=linesrch(hom, H, W, D, posx, posy, -1, 0)
    count+=linesrch(hom, H, W, D, posx, posy, 0, -1)
    return count
for casenum in range(1, cases+1):
    #Begin parsing for one problem starting at line linenum
    vars = lines[linenum].split(' ')
    H = int(vars[0])
    W = int(vars[1])
    D = int(vars[2])
    hom = lines[linenum+1:linenum+1+H]
    linenum = linenum+1+H
    out = solve(hom, H, W, D) #Assign solved value
    #End parsing
    casestr = 'Case #'+str(casenum)+': '+str(out)
    print (casestr)
    outfile.write(casestr+"\n")
