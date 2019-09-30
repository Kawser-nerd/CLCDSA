from collections import Counter
N=int(input())
X=list(map(int,input().split()))
Y=sorted(X)
a=Y[N//2]
b=Y[N//2-1]
for i in X:
    if i<=b:
        print(a)
    else:
        print(b)