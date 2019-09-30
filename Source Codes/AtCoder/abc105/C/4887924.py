n = int(input())

def baseNeg2(N: int) -> str:
        negTwoL = [0]*32
        index = len(negTwoL)-1
        if N >=0:
            while index > -1:
                if N >= 2**index:
                    if index % 2 == 0:
                        negTwoL[index] += 1
                    else:
                        negTwoL[index] += 1
                        negTwoL[index+1] += 1
                    N -= 2**index
                index -= 1
        else:
            N=-N
            while index > -1:
                if N >= 2**index:
                    if index % 2 == 1:
                        negTwoL[index] += 1
                    else:
                        negTwoL[index] += 1
                        negTwoL[index+1] += 1
                    N -= 2**index
                index -= 1

        if N >= 0:
            flag = 1
            while flag:
                flag = 0
                index2 = 0
                while index2 < len(negTwoL)-2:
                    if negTwoL[index2] > 1:
                        flag = 1
                        if negTwoL[index2] % 2 == 0:
                            if negTwoL[index2+1] == 1:
                                negTwoL[index2+1] = 0
                            else:
                                negTwoL[index2+1] += 1
                                negTwoL[index2+2] += 1
                            negTwoL[index2] = 0
                        else:
                            if negTwoL[index2+1] == 1:
                                negTwoL[index2+1] = 0
                            else:
                                negTwoL[index2+1] += 1
                                negTwoL[index2+2] += 1
                            negTwoL[index2] = 1
                    index2 += 1
        else:
            flag = 1
            while flag:
                flag = 0
                index2 = 2
                while index2 < len(negTwoL):
                    if negTwoL[index2] > 1:
                        flag = 1
                        if negTwoL[index2] % 2 == 1:
                            if negTwoL[index2+1] == 1:
                                negTwoL[index2+1] = 0
                            else:
                                negTwoL[index2-1] += 1
                                negTwoL[index2-2] += 1
                            negTwoL[index2] = 0
                        else:
                            if negTwoL[index2+1] == 1:
                                negTwoL[index2+1] = 0
                            else:
                                negTwoL[index2+1] += 1
                                negTwoL[index2+2] += 1
                            negTwoL[index2] = 1
                    index2 += 1
        negTwoL.reverse()
        while True:
            if len(negTwoL) == 1:
                break
            else:
                if negTwoL[0] == 0:
                    del negTwoL[0]
                else:
                    break
        return "".join(list(map(str, negTwoL)))


print(baseNeg2(n))