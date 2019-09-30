a,b= map(int,input().split(" "))
c = int(input())
ar = list(map(int,input().split(" ")))
br = [[0 for i in range(b)] for j in range(a)]
go = "M"
ap = 1
for i in range(a):
    if go == "M":
        for j in range(b):
            if ar[0] == 0:
                del ar[0]
                ap += 1
            br[i][j] = ap
            ar[0] -= 1
        go = "U"
    else:
        for j in range(b-1,-1,-1):
            if ar[0] == 0:
                del ar[0]
                ap += 1
            br[i][j] = ap
            ar[0] -= 1
        go = "M"
for r in br:
    for i in range(b-1):
        print(r[i],end=" ")
    print(r[b-1])