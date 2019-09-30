import bisect

N, K = input().split()
dList = [int(x) for x in input().split()]
useList = [0,1,2,3,4,5,6,7,8,9]
for d in dList:
    useList.remove(d)
result = ''
if int(N[0]) > max(useList):
    # ??????
    if useList[0] != 0:
        result += str(useList[0])
    else:
        result += str(useList[1])
    result += str(useList[0])*(len(N))
else:
    for i in range(len(N)):
        a = int(N[i])
        if a in useList:
            result += N[i]
            continue
        else:
            count = 0
            if a > max(useList):
                while not max(useList) > int(result[-1]):
                    count += 1
                    result = result[:-1]
                    if result == '':
                        break
                if result == '':
                    if useList[0] != 0:
                        result += str(useList[0])
                    else:
                        result += str(useList[1])
                    result += str(useList[0])*(len(N))
                    break
                count += 1
                sect = int(result[-1])
                result = result[:-1]
                result += str(useList[bisect.bisect_right(useList, sect)])
                result += str(useList[0])*(len(N)-len(result))
            else:
                result += str(useList[bisect.bisect_right(useList, a)])
                result += str(useList[0])*(len(N)-i-1)
            break
print(result)