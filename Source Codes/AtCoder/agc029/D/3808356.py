import sys
def ?():
    input = sys.stdin.readline
    H,W,N = [int(_) for _ in input().split()]
    dT={}
    ?? = H
    if N :
        for  _ in range(N):
            x,y = [int(_) - 1 for _ in input().split()]
            #?????????????
            #x=y????????????????
            if x >= y:
                ?? = x-y
                ?? = x+y
                if ?? in dT:
                    if ?? < dT[??][2] :
                        dT[??] = (x,y,??)
                else:
                    dT[??] = (x,y,??)
        aB = sorted(dT.items())
        iL = len(aB)
        if iL == 1:
            #x=y??????????
            if 0 < aB[0][0] :
                ?? = aB[0][1][0]
        elif 1 < iL :
            aG= [aB[0][1]] #?????
            #??????????????
            #?????????????????????????????
            for i in range(1,iL):
                if aB[i][0]-1 == aB[i-1][0]:
                    if aB[i][1][2] < aB[i-1][1][2] :
                        aG.append(aB[i][1])
                else:
                    aG.append(aB[i][1])
            #???x=y??????
            if len(aG) and aG[0][0] - aG[0][1] == 0 :
                del aG[0]
            #x????
            if len(aG):
                #??,??,?? = sorted(aG,key=lambda x:x[0])[0]
                ?? = sorted(aG)[0][0]
    print(??)
?()