N=int(input())
X=[]
U=[]
for i in range(N):
    x,u=input().split()
    X.append(float(x))
    U.append(u)
    if U[i]=='BTC':
        X[i]=380000*X[i]
print(sum(X))