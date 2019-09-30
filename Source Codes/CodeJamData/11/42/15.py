def f(R,C,M,D):
    for i in range(R):
        for j in range(C):
            M[i][j]+=D
    def isincenter(x,y,w):
        xc=yc=w/2
        rx=ry=0
        for i in range(w):
            for j in range(w):
                if (i==0 and j==0) or (i==0 and j==w-1) or (j==0 and i==w-1) or (i==w-1 and j==w-1):
                    continue
                rx+=(i+0.5-xc)*M[x+i][y+j]
                ry+=(j+0.5-yc)*M[x+i][y+j]
##        print(x,y,w,rx,ry)
        return rx==ry==0
    for k in range(min(R,C),2,-1):
        for i in range(0,R-k+1):
            for j in range(0,C-k+1):
                if isincenter(i,j,k):
##                    print(i,j,k)
                    return k
##    print(M)
    return "IMPOSSIBLE"
def main():
    with open('B-small-attempt1.in') as fin,\
         open('B-small-attempt1.out','w') as fout:
        rstr=lambda f:next(f).rstrip()
        rstrs=lambda f:rstr(f).split()
        rint=lambda f:int(next(f).rstrip())
        rints=lambda f:list(map(int,next(f).strip().split()))
        rints2=lambda f:list(map(int,next(f).strip()))
        for i in range(rint(fin)):
            R,C,D=rints(fin)
            M=[rints2(fin) for j in range(R)]
            re=f(R,C,M,D)
            print(str.format("Case #{0}: {1}",i+1,re))
            print(str.format("Case #{0}: {1}",i+1,re),file=fout)
main()
