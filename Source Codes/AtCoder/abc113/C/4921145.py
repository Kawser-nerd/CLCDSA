N,M = map(int,input().split())
PY = [list(map(int,input().split())) for _ in range(M)]
for i in range(M):
    PY[i].append(i)
PY.sort(key=lambda x:x[1])
ans = [0]*M
num = [0]*N
for p,y,i in PY:
    ans[i] = str(p).zfill(6) + str(num[p-1]+1).zfill(6)
    num[p-1] += 1
for s in ans:print(s)