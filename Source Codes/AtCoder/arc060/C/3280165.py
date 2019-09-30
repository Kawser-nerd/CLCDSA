N = int(input())
X = list(map(int, input().split()))
L = int(input())
Q = int(input())

V = [0]*N
ib = 0
for i in range(N):
    while X[i]-X[ib] > L:
        V[ib] = i-1
        ib += 1
while ib!=N-1:
    V[ib]=N-1
    ib += 1
dbl = [[0]*N for i in range(18)]
dbl[0]=V
for i in range(1, 18):
    for j in range(N):
        ii = dbl[i-1][j]
        if ii == 0:
            break
        dbl[i][j] = dbl[i-1][ii]
for i in range(Q):
    a, b = map(int, input().split())
    a, b = sorted([a, b])
    a-=1
    b-=1
    ind = a
    ans = 0
    for j in range(17, -1, -1):
        if dbl[j][ind]==0:
            continue
        if dbl[j][ind]>b:
            continue
        if dbl[j][ind]==b:
            ans |= 1<<j
            break
        else:
            ans |= 1<<j
            ind = dbl[j][ind]
    else:
        ans += 1
    print(ans)