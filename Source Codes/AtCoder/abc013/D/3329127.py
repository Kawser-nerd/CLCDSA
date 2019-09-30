def ?():
    iN,iM,iD = [int(_) for _ in input().split()]
    aA = [int(_) for _ in input().split()]

    #??1
    aN = [_ for _ in range(iN+1)]
    for iE in aA[::-1]:
        aN[iE],aN[iE+1] = aN[iE+1],aN[iE]
    #??????????????????
    #????????????????
    a?=[False]*(iN+1)
    aRet = [None]*(iN+1)
    for i in range(1,iN+1):
        if not a?[i] :
            aT = [i]
            a?[i] = True
            iNext = aN[i]
            while True:
                if iNext == i:
                    break
                aT.append(iNext)
                a?[iNext]=True
                iNext = aN[iNext]
            #????????????D????????????
            iL = len(aT)
            if iL == 1:
                aRet[i]=i
            else:
                i?? = iD % iL
                for j in range(iL):
                    aRet[aT[j]] = aT[(j+i??) % iL]
    print("\n".join([str(_) for _ in aRet[1:]]))

?()