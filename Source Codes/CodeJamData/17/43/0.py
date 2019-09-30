from sys import stdin,stderr
from subprocess import Popen, PIPE

def doLparse(files, constants, bound, processingScript):
    txt = ["lparse"]
    for (k, l) in constants.items():
        txt.append("-c")
        txt.append("{}={}".format(k,l))
    p1 = Popen(txt + files, stdout = PIPE)
    p2 = Popen(["smodels", str(bound)], stdin = p1.stdout, stdout = PIPE)
    if processingScript != "":
        p3 = Popen(["python", processingScript], stdin = p2.stdout, stdout = PIPE)
    else:
        p3 = p2
    (a, b) = p3.communicate()
    return a

def solve(tc,ns,covers,forbidden):
    fn = "logic%d.lp" % tc
    temp = open(fn,"w")
    for i in xrange(ns):
        temp.write("{h%d}.\n"%i)
        temp.write("{v%d}.\n"%i)
        temp.write(":- h%d, v%d.\n"%(i,i))
        temp.write(":- not h%d, not v%d.\n"%(i,i))
    for (i,j) in forbidden:
        if j == "-":
            temp.write(":- h%d.\n" % i)
        else:
            temp.write(":- v%d.\n" % i)
    for cover in covers:
        things = []
        for (i,j) in cover:
            if j == "-":
                things.append("not h%d" % i)
            else:
                things.append("not v%d" % i)
        temp.write(":- {}.\n".format(", ".join(things)))
    temp.close()
    print >>stderr, fn
    output = doLparse([fn], {}, 1, "")
    return [line for line in output.split("\n") if "table" in line]

def getInts():
    return tuple(int(z) for z in stdin.readline().split())

(T,)=getInts()

for tc in xrange(1,1+T):
    (R,C) = getInts()
    house = [[z for z in stdin.readline().strip()] for i in xrange(R)]
    dots = [(i,j) for i in xrange(R) for j in xrange(C) if house[i][j] == "."]
    shooters = [(i,j) for i in xrange(R) for j in xrange(C) if house[i][j] == "-" or house[i][j] == "|"]
    walls = [(i,j) for i in xrange(R) for j in xrange(C) if house[i][j] == "#"]
    covers = [set([]) for z in dots]
    forbidden = set([])
    ns = len(shooters)
    for k in xrange(ns):
        (i,j) = shooters[k]
        for dr in [(-1,0),(1,0),(0,-1),(0,1)]:
            thing = (k,"-|"[abs(dr[0])])
            (dx,dy) = dr
            (bx,by) = (i+dx, j+dy)
            covered = []
            while True:
                if bx < 0 or bx >= R or by < 0 or by >= C or house[bx][by] == "#":
                    break
                elif house[bx][by] == "-" or house[bx][by] == "|":
                    forbidden.add(thing)
                    break
                elif house[bx][by] == ".":
                    covers[dots.index((bx,by))].add(thing)
                elif house[bx][by] == "\\":
                    # (0,1) -> (1,0) and vice verse
                    (dx,dy) = (dy,dx)
                elif house[bx][by] == "/":
                    # (0,1) -> (-1,0) and vice versa
                    (dx,dy) = (-dy,-dx)
                else:
                    print >>stderr, ("?"*200)
                (bx,by) = (bx+dx,by+dy)
    if any(len(cover) == 0 for cover in covers):
        soln2 = []
    else:
        soln2 = solve(tc,ns, covers, forbidden)
    print >>stderr, "Solved."
    if len(soln2) == 0:
        print "Case #{}: IMPOSSIBLE".format(tc)
        continue
    else:
        soln2 = soln2[0].split(": ")[1].split()        
        choices = [(int(k[1:]),"-" if k[0] == 'h' else "|") for k in soln2]
        if any(choice in forbidden for choice in choices):
            print >>stderr, "??FORBIDDEN"
        if any(len([k for k in cover if k in choices]) == 0 for cover in covers):
            print >>stderr, "??COVER"            
        for k in soln2:
            i = int(k[1:])
            (sx,sy) = shooters[i]
            if k[0] == 'h':
                house[sx][sy] = "-"
            else:
                house[sx][sy] = "|"
        print "Case #{}: POSSIBLE".format(tc)
        print "\n".join("".join(row) for row in house)

