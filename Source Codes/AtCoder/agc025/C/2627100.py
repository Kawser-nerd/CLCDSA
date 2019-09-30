N=int(input())
LR=[None]*N
for i in range(N):
    LR[i]=list(map(int,input().split()))

RAN=(len(LR)+1)//2

LR_L=sorted(LR,key=lambda x: x[0],reverse=True)
LR_R=sorted(LR,key=lambda x: x[1])

ANS_l=[0]*(RAN*2+2)
ANS_r=[0]*(RAN*2+2)

for i in range(RAN):
    ANS_l[2*i+1]=ANS_l[2*i]+LR_L[i][0]
    ANS_l[2*i+2]=ANS_l[2*i+1]-LR_R[i][1]

    ANS_r[2*i+1]=ANS_r[2*i]-LR_R[i][1]
    ANS_r[2*i+2]=ANS_r[2*i+1]+LR_L[i][0]


print(max(max(ANS_l)*2,max(ANS_r)*2))