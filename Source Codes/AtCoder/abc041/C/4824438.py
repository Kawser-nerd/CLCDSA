n=int(input())

A=list(map(int,input().split()))
X=[]
for k,v in enumerate(A):
    X.append([k,v])

X=sorted(X,key=lambda x:x[1],reverse=True)

for i in range(n):
    print(X[i][0]+1)