N=int(input())
X=[]
Y=[]
Z=[]
for i in range(N):
    a=list(map(int,input().split()))
    a.sort()
    X.append(a[0])
    Y.append(a[1])
    Z.append(a[2])
X.sort(reverse=True)
Y.sort(reverse=True)
Z.sort(reverse=True)
print(X[0]*Y[0]*Z[0])