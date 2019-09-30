def chk(h,w):
    for i in range(1,8):
        if 0<=1*i+h<8 and 0<=0*i+w<8 and b[1*i+h][0*i+w]=="Q": return 0
        if 0<=-1*i+h<8 and 0<=0*i+w<8 and b[-1*i+h][0*i+w]=="Q": return 0
        if 0<=0*i+h<8 and 0<=-1*i+w<8 and b[0*i+h][-1*i+w]=="Q": return 0
        if 0<=0*i+h<8 and 0<=1*i+w<8 and b[0*i+h][1*i+w]=="Q": return 0
        if 0<=-1*i+h<8 and 0<=-1*i+w<8 and b[-1*i+h][-1*i+w]=="Q": return 0
        if 0<=1*i+h<8 and 0<=-1*i+w<8 and b[1*i+h][-1*i+w]=="Q": return 0
        if 0<=-1*i+h<8 and 0<=1*i+w<8 and b[-1*i+h][1*i+w]=="Q": return 0
        if 0<=1*i+h<8 and 0<=1*i+w<8 and b[1*i+h][1*i+w]=="Q": return 0
    return 1

def dfs(c,g):
    if c==0:
        for i in b: print(*i, sep="")
        exit()
    for y in range(g,8):
        for x in range(8):
            if b[y][x]=="Q" or chk(y,x)==0: continue
            b[y][x]="Q"
            dfs(c-1,g+1)
            b[y][x]="."
q=0
b=[]
for i in range(8):
    tmp=list(input())
    q+=tmp.count("Q")
    b.append(tmp)
for i in range(64):
    if b[i//8][i%8]=="Q" and chk(i//8,i%8)==0:
        print("No Answer")
        exit()
q=8-q
dfs(q,0)
print("No Answer")