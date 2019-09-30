# Debug Print
isdbg  = False
#isdbg  = True
def dprint(*value,sep=' ',end='\n'):
    if isdbg:
        print(*value,sep=sep,end=end)
    
# ?????
H,W,N = map(int,input().split())

if isdbg:
    XY = [[0 for i in range(W)] for i in range(H)]
BL = {}
for i in range(N):
    x1,y1 = map(int,input().split())
    if isdbg:
        XY[x1-1][y1-1] = 1

    if x1-1 in BL :
        BL[x1-1].append(y1-1)
    else:
        BL[x1-1] = [y1-1]

TL = sorted(BL.items(),key= lambda x: x[0])

# ????
if isdbg:
    for i in range(W):
        for j in range(H):
            dprint(XY[i][j],end='')
        dprint()
#print(TL)

maxr = 1
for i in range(H-1):

    if i+1 in BL:
        l = BL[i+1]
        l.sort()
        #print(l,maxr)
        for ll in l :
            if maxr > ll:
                print(i+1)
                exit(0)
            elif maxr == ll:
                maxr -= 1
                break
            else:
                break
        
    maxr += 1

print(H)