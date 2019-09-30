n,w = map(int, input().split())
w4 = [[] for i in range(4)]
w1 = None
for i in range(n):
    ws, vs = map(int,input().split())
    if i == 0:
        w1 = ws
    ws -= w1
    w4[ws].append(vs)

for i in range(4):
    w4[i].sort(reverse=True)
    tmp = [0]
    for j in w4[i]:
        tmp.append(tmp[-1]+j)
    w4[i] = tmp
ans = 0
for i in range(len(w4[0])):
    for j in range(len(w4[1])):
        for k in range(len(w4[2])):
            for l in range(len(w4[3])):
                if w >= w1*(i+j+k+l) + j + 2*k + 3*l:
                    ans = max(ans, w4[0][i]+w4[1][j]+w4[2][k]+w4[3][l])
print(ans)