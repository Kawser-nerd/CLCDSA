N,A=map(int,input().split())

X=list(map(int,input().split()))
x=[]
for i in range(N):
    x.append(X[i]-A)

L=[0 for i in range(5001)]
L[2500]=1

for i in range(N):
    if x[i]>=0:
        for j in range(5001):
            if L[5000-j]>0:
                L[5000-j+x[i]]+=L[5000-j]
    elif x[i]<0:
        for j in range(5001):
            if L[j]>0:
                L[j+x[i]]+=L[j]
print(L[2500]-1)