from collections import defaultdict as dd

N, M = [int(i) for i in input().split()]
xyList = [[int(i) for i in input().split()] for _ in range(M)]

xyDict = dd(set)
for xy in xyList:
    xyDict[xy[0]].add(xy[0])
    xyDict[xy[1]].add(xy[1])
    xyDict[xy[0]].add(xy[1])
    xyDict[xy[1]].add(xy[0])

ans = 1
for i in range(2 ** N):
    strBin = str(bin(i)[2:]).zfill(N)
    group = []
    index = -1
    while(True):
        index = strBin.find("1", index + 1)
        if index == -1:
            break
        group.append(index + 1)

    ansFlag = True
    for g in group:
        for g1 in group:
            if not g1 in xyDict[g]:
                ansFlag = False
                break


    if ansFlag:
        ans = max(len(group), ans)


print(ans)