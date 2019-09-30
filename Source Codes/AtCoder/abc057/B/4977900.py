n,m = map(int,input().split())
piv = []
check = []
for i in range(n):
    a,b = map(int,input().split())
    piv.append([a,b])
for i in range(m):
    c,d = map(int,input().split())
    check.append([c,d])


for i in range(n):
    tmp = 1000000000
    ans = 0

    for j in range(m):
        x = abs(piv[i][0] - check[j][0]) + abs(piv[i][1] - check[j][1])
        if tmp > x:
            ans = j + 1
            tmp = x

    print(ans)