N = int(input())
barr = list(map(int,input().split()))
cntb = []
for i in range(N):
    cntb.append([barr[i],i])
task = []
ok = True
for n in range(N):
    for i in range(N)[::-1]:
        if cntb[i][1]+1 == cntb[i][0]:
            task.append(cntb[i][0])
            cntb[i][0] = -1
            break
        elif cntb[i][0] > 0 and cntb[i][1] + 1 < cntb[i][0]:
            ok = False
        else:
            cntb[i][1] -= 1

if ok:
    for i in range(N)[::-1]:
        print(task[i])
else:
    print(-1)