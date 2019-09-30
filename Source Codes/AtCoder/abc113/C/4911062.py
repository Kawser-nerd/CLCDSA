N,M = map(int,input().split())

PY = [[0,0,0,0] for i in range(M)] #index,p,y,number

for m in range(M):
    PY[m][0] = m
    PY[m][1],PY[m][2] = map(int,input().split())

PY.sort(key=lambda x:x[2])
cnt = [0]*(N+1)

for m in range(M):
    cnt[PY[m][1]] += 1
    PY[m][3] = cnt[PY[m][1]]

PY.sort(key=lambda x:x[0])

for m in range(M):
    print(str(PY[m][1]).zfill(6) + str(PY[m][3]).zfill(6))