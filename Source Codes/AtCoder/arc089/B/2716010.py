N,K=map(int,input().split())
table=[[0]*K for i in range(K)]#W=1
C=0
for i in range(N):
    x,y,z=input().split()
    x = int(x)
    y=int(y)
    if z=='B':
        y +=K
    x %=(2*K)
    y %=(2*K)
    t = (x//K +y//K)%2
    x%= K
    y%=K
    if t:
        table[y][x]-=1
    else:
        table[y][x]+=1
        C+=1
B=N-C
#print(table)
pr=[[0]*(K+1) for i in range(K)]
for i in range(K):
    for j in range(K):
        pr[j][i+1]=pr[j][i]+table[j][i]
#print(pr)
pr2=[[0]*(K+1) for i in range(K+1)]
for j in range(K):
    for i in range(K):
        pr2[j+1][i+1]=pr2[j][i+1]+pr[j][i+1]
#print(pr2)
ans = 0
for i in range(K+1):
    for j in range(K+1):
        #s=pr2[K][K]-pr2[i-1][K] -pr2[K][j-1]+2*pr2[i-1][j-1]
        s =pr2[i][K] +pr2[K][j]-2*pr2[i][j]
        #??????????????????
        #t=pr2[K][K]-s#????
        #print(s,t,s-t,C-s)
        ans = max(ans,C-s,B+s)
print(ans)