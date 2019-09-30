n = int(input())
lis = list(map(int,input().split()))
nu1 = 0
nu2 = 0
nu4 = 0
for nu in lis:
    if nu % 2 == 0:
        if nu % 4 == 0:
            nu4 += 1
        else:
            nu2 = 1
    else:
        nu1 += 1
if nu4 + 1 >= nu1 + nu2:print("Yes")
else:print("No")