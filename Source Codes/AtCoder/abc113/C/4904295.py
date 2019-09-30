N,M = list(map(int,input().split()))
PY = []
DD = [0 for i in range(N+1)]
for i in range(M):
    P,Y = list(map(int,input().split()))
    PY.append((P,Y,i,""))
PY.sort()
DY = []
for i in PY:
    DY.append((i[2],str(i[0]).zfill(6) + str(DD[i[0]]+1).zfill(6)))
    DD[i[0]] = DD[i[0]] + 1
DY.sort()
for i in DY:
    print(i[1])