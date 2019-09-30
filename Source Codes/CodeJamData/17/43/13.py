HORIZ = '-'
VERTI = '|'
SHOOTER = {'|', '-'}
EMPTY = '.'
WALL = '#'
IMP = 'IMPOSSIBLE'
from itertools import groupby
def check(A):
    todo = set()
    did = set()
    for r, row in enumerate(A):
        cc = 0
        for k, g in groupby(row, key =lambda x: x!=WALL):
            grp = "".join(g)
            if k:
                ch = grp.count(HORIZ)
                cv = grp.count(VERTI)
                ce = grp.count(EMPTY)
                if (ch > 1) or (ch == 1 and cv):
                    return False
                if ce:
                    if (not ch):
                        for c, val in enumerate(grp):
                            if val == EMPTY:
                                todo.add((r, cc+c))
                    else:
                        for c, val in enumerate(grp):
                            if val == EMPTY:
                                did.add((r, cc+c))
            cc += len(grp)

    for c, col in enumerate(zip(*A)):
        rr = 0
        for k,g in groupby(col, key=lambda x: x!=WALL):
            grp = "".join(g)
            if k:
                ch = grp.count(HORIZ)
                cv = grp.count(VERTI)
                ce = grp.count(EMPTY)
                if (cv > 1) or (cv == 1 and ch):
                    return False
                if ce:
                    if (not cv):
                        #all squares better be done else false
                        for r, val in enumerate(grp):
                            if val == EMPTY:
                                if (rr+r,c) not in did:
                                    return False
                    else:
                        for r, val in enumerate(grp):
                            if val == EMPTY:
                                todo.discard((rr+r, c))

            rr += len(grp)
    return not todo

    
def solve(R, C, A):
    #every cell has a beam
    #no beams destroyed
    A = [list(row) for row in A]
    vari = set()
    for r, row in enumerate(A):
        for c, val in enumerate(row):
            if val in SHOOTER:
                vari.add((r, c))
    for r, row in enumerate(A):
        cc = 0
        for k, g in groupby(row, key = lambda x: x!=WALL):
            grp = "".join(g)
            if k:
                ch = grp.count(HORIZ)
                cv = grp.count(VERTI)
                ce = grp.count(EMPTY)
                if ch + cv > 1: #all vert
                    for c, val in enumerate(grp):
                        if val in SHOOTER:
                            A[r][cc + c] = VERTI
                            vari.discard((r, cc+c))
                #elif (ch + cv == 1) and ce:
                #    for c, val in enumerate(grp):
                #        if val in SHOOTER:
                #            A[r][cc + c] = HORIZ
                #            vari.discard((r, cc+c))
            cc += len(grp)

    for c, col in enumerate(zip(*A)):
        rr = 0
        for k, g in groupby(col, key = lambda x: x!=WALL):
            grp = "".join(g)
            if k:
                ch = grp.count(HORIZ)
                cv = grp.count(VERTI)
                ce = grp.count(EMPTY)
                if ch + cv > 1:
                    #all horiz
                    for r, val in enumerate(grp):
                        if val in SHOOTER:
                            A[rr+r][c] = HORIZ
                            vari.discard((rr+r,c))
                #elif (ch+cv==1) and ce:
                #    for r, val in enumerate(grp):
                #        if val in SHOOTER:
                #            A[rr+r][c] = VERTI
                #            vari.discard((rr+r, c))
            rr += len(grp)

    R, C = len(A), len(A[0])
    def stranded(r, c):
        return ((r==0 or A[r-1][c] == WALL) and
                (r==R-1 or A[r+1][c] == WALL) and
                (c==0 or A[r][c-1] == WALL) and
                (c==C-1 or A[r][c+1] == WALL))
    
    for v in list(vari):
        if stranded(*v):
            vari.discard(v)

    for r, c in vari:
        A[r][c] = VERTI
    if check(A): return '\n'.join(['POSSIBLE'] + ["".join(row) for row in A])
    for r, c in vari:
        A[r][c] = HORIZ
    if check(A): return '\n'.join(['POSSIBLE'] + ["".join(row) for row in A])

    from itertools import product
    vari  =list(vari)
    for cand in product([HORIZ+VERTI for _ in xrange(len(vari))]):
        for (r,c), val in zip(vari, cand):
            A[r][c] = val
        if check(A): return '\n'.join(['POSSIBLE'] + ["".join(row) for row in A])
    return 'IMPOSSIBLE'
    

###
def main():
    with open('in.txt','r') as fi, \
            open('out.txt', 'w') as fo:
        rr = lambda: fi.readline().strip()
        rrM = lambda: map(int,rr().split())
        for tc in xrange(1, 1 + int(rr())):
            R, C = rrM()
            A = [rr() for _ in xrange(R)]
            zeta = solve(R,C,A)
            outstr = "Case #%i: " % tc + str(zeta)
            print outstr
            fo.write(outstr+'\n')
            
if __name__ == "__main__": main()
