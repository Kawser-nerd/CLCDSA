N = int(input())
A = [tuple(map(int,input().split())) for i in range(N)]
D = 0
for Cx in range(101):
    for Cy in range(101):
        H = 0
        F = 1
        for i in A:
            if H < 1:
                if i[2] == 0:
                    continue
                H = i[2] + abs(i[0]-Cx) + abs(i[1]-Cy)
            elif i[2] == max(H-abs(i[0]-Cx)-abs(i[1]-Cy),0):
                continue
            else:
                F = 0
                break
        for i in A:
            if not (i[2] == max(H-abs(i[0]-Cx)-abs(i[1]-Cy),0)):
                F = 0
                break
        if F == 1 and H >= 1 and D == 0:
            D = 1
            print(Cx,Cy,H)