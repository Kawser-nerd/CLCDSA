import sys
# N=??????19
N = 19
# ???
arrList = [[0 for i in range(N)] for j in range(N)]
# ?????
blackGo = 0
whiteGo = 0

# ???????0??N???????False
def inBoardCheck(Xval, Yval):
    if 0 <= Xval < N and 0 <= Yval < N:
        return True
    else:
        return False

def check5():
    # ??8?????
    moveXval = [1,1,1,0,0,-1,-1,-1]
    moveYval = [1,0,-1,1,-1,1,0,-1]
    # i=??j=?
    for i in range(N):
        for j in range(N):
            if arrList[i][j] != 0:
                nowVal = arrList[i][j]
                for k in range(8):
                    returnFlag = True
                    # 5??????????????????????Break
                    for l in range(5):
                        # ??????????????Break????l?5??????
                        intXval = i + moveXval[k] * l
                        intYval = j + moveYval[k] * l
                        # ???????????????????????????False
                        if (inBoardCheck(intXval,intYval) != True or arrList[intXval][intYval] != nowVal):
                            returnFlag = False
                            break
                    # 5???????????????False
                    if returnFlag == True:
                        return False

    # ??????????True
    return True

# ???_???????????
for i in range(N):
    # input
    goBan = input()
    for j in range(N):
        if goBan[j] == 'o':
            arrList[i][j] = 1
            blackGo += 1

        if goBan[j] == 'x':
            arrList[i][j] = 2
            whiteGo += 1

player = 0
# ??1??????????????????????
if blackGo - 1 == whiteGo:
    player = 1
if blackGo == whiteGo:
    player = 2

# ?????????????
if player == 0:
    print("NO")
    sys.exit()

# ??????????OK
if blackGo == 0:
    print("YES")
    sys.exit()

# ??????????????
for i in range(N):
    for j in range(N):
        # ????????????
        if arrList[i][j] == player:
            # ????????
            arrList[i][j] = 0
            # ????????True??YES
            if check5() == True:
                print("YES")
                sys.exit()
            # 5???????????????????
            arrList[i][j] = player
# ????????????????NO??
print("NO")