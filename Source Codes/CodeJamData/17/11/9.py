
import sys
sys.stdin=open("data.txt")
sys.stdout=open("out.txt","w")
input=sys.stdin.readline

for cnum in range(int(input())):
    print("Case #%d:"%(cnum+1))
    r,c=map(int,input().split())
    g=[list(input().strip()) for _ in range(r)]
    # fill rows
    started=0
    for i in range(r):
        if not started:
            for j in range(c):
                if (not started) and g[i][j]!='?':
                    started=1
                elif started and g[i][j]=='?':
                    g[i][j]=g[i][j-1]
            if started:
                for j in range(c)[::-1]:
                    if g[i][j]=='?':
                        g[i][j]=g[i][j+1]
                    for ii in range(i):
                        g[ii][j]=g[i][j]
        else:
            for j in range(c):
                if j and g[i][j]==g[i][j-1]: continue
                # try substring
                jj=j
                hit=0
                if g[i][j]!='?': hit=1
                while jj+1<c and g[i-1][j]==g[i-1][jj+1]:
                    jj+=1
                    if g[i][jj]!='?': hit=1
                if not hit:
                    for jjj in range(j,jj+1):
                        g[i][jjj]=g[i-1][jjj]
                else:
                    # split substring
                    hit=0
                    for jjj in range(j,jj+1):
                        if not hit:
                            if g[i][jjj]!='?':
                                for j4 in range(j,jjj):
                                    g[i][j4]=g[i][jjj]
                                hit=1
                        elif g[i][jjj]=='?':
                            g[i][jjj]=g[i][jjj-1]
    for i in g: print("".join(i))
