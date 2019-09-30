N,X =map(int,input().split())
Z =[]
ALL =0
for i in range(N):
    Y = int(input())
    ALL+=Y
    Z.append(Y)

ANS = (X- ALL)//(min(Z))
if ANS ==0:
    print(len(Z))
else:
    print(ANS+len(Z))