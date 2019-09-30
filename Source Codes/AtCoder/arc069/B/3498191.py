N=int(input())
s=input()
S=[1 if i=="o" else -1 for i in s]
#print(S)
X=[[0 for i in range(N)] for i in range(4)]
X[0][0]=1
X[0][1]=1
X[1][0]=1
X[1][1]=-1
X[2][0]=-1
X[2][1]=1
X[3][0]=-1
X[3][1]=-1
for k in range(4):
    for i in range(2,N):
        if S[i-1]*X[k][i-1]==1:
            X[k][i]=X[k][i-2]
        else:
            X[k][i]=-X[k][i-2]
    flag=0
    for i in range(2):
        if S[i-1]*X[k][i-1]==1:
            if X[k][i]!=X[k][i-2]:
                flag=1
        else:
            if X[k][i]!=-X[k][i-2]:
                flag=1
    if flag==0:
        T=""
        for i in range(N):
            if X[k][i]==1:
                T=T+"S"
            else:
                T=T+"W"
        print(T)
        exit()
print(-1)