import sys
def ?():
    iN,iM,iD = [int(_) for _ in input().split()]
    aA = [int(_) for _ in input().split()]

    #??1
    aN = list(range(iN+1))
    for i in range(iM-1,-1,-1):
        aN[aA[i]],aN[aA[i]+1] = aN[aA[i]+1],aN[aA[i]]


    #??3
    aN[0] = 1
    aB = [aN]
    for i in range(1,30): # 2^29 < 10^9 < 2^30
        aT = [0]*(iN+1)
        for j in range(1,iN+1):
            aT[j] = aB[-1][aB[-1][j]]
        aT[0] = aB[-1][0]*2
        aB.append(aT)
        if iD / 2 <= aT[0]:
            break
    aRet = list(range(iN+1))
    for i in range(len(aB)-1,-1,-1):
        if aB[i][0]  <= iD :
            for j in range(1,iN+1):
                aRet[j] = aB[i][aRet[j]]
            iD -= aB[i][0]
    sys.stdout.write("\n".join([str(_) for _ in aRet[1:]])+"\n")
if __name__ == '__main__':
    ?()