h, w = map(int, input().split())
A = [input() for i in range(h)]

flag = 0
for a in A:
    X = a.split('.')
    cnt = 0
    for x in X:
        if '#' in x:
            cnt += 1
    if cnt > 1:
        flag = 1
        
if flag:
    ans = 'Impossible'
else:
    ans = 'Possible'
    posi = 0
    for i in range(h):
        B = []
        for j in range(w):
            if A[i][j] == '#':
                B.append(j)
        if B[0] > posi or B[0] < posi:
            ans = 'Impossible'
            break
        else:
            posi = B[-1]

print(ans)