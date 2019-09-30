N=int(input())
X=list(map(int,input().split()))
Y=X[:]
Y.sort()
for i in range(N):
    if X[i]<=Y[int(N/2)-1]:
        print(Y[int(N/2)])
    else:
        print(Y[int(N/2)-1])