N,C=map(int,input().split())
D=[]
for i in range(C):
    d=list(map(int,input().split()))
    D.append(d)
    
mod0=[0 for i in range(C)]
mod1=[0 for i in range(C)]
mod2=[0 for i in range(C)]

Arr=[]
for i in range(N):
    c=list(map(int,input().split()))
    Arr.append(c)
    
for i in range(N):
    for j in range(N):
        if (i+j)%3==0:
            mod0[Arr[i][j]-1]+=1
        elif (i+j)%3==1:
            mod1[Arr[i][j]-1]+=1
        elif (i+j)%3==2:
            mod2[Arr[i][j]-1]+=1

MOD0=[]
MOD1=[]
MOD2=[]

for i in range(C):
    cnt0=0
    cnt1=0
    cnt2=0
    for j in range(C):
        cnt0+=mod0[j]*D[j][i]
        cnt1+=mod1[j]*D[j][i]
        cnt2+=mod2[j]*D[j][i]
    MOD0.append(cnt0)
    MOD1.append(cnt1)
    MOD2.append(cnt2)
ans=10**15
for a in range(len(MOD0)):
    for b in range(len(MOD0)):
        for c in range(len(MOD0)):
            if a==b or b==c or c==a:
                pass
            else:
                if MOD0[a]+MOD1[b]+MOD2[c]<ans:
                    ans=MOD0[a]+MOD1[b]+MOD2[c]
print(ans)