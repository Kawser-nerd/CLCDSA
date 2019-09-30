N = int(input())
L = []
ans = [0,0,0,0,0,0]
for i in range(N):
    L.append(list(map(float,input().split())))
for i in range(N):
    if L[i][0] >= 35:
        ans[0] += 1
    elif L[i][0] >= 30:
        ans[1] += 1
    elif L[i][0] >= 25:
        ans[2] += 1
    elif L[i][0] < 0:
        ans[5] += 1
for j in range(N):
    if L[j][1] >= 25:
        ans[3] += 1
    else:
        if L[j][1] < 0 and L[j][0] >= 0:
            ans[4] += 1
print(str(ans[0])+' '+str(ans[1])+' '+str(ans[2])+' '+str(ans[3])+' '+str(ans[4])+' '+str(ans[5]))