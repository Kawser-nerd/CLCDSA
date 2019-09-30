N=int(input())
X=[0 for i in range(N)]
if N%2==0:
    for i in range(N//2):
        X[i]=i+1
        X[-i-1]=i+1
else:
    for i in range(N//2):
        X[i]=i+1
        X[-i-2]=i+1
    X[-1]=N//2+1
edge=[]
for i in range(N):
    for j in range(N):
        if i<=j:
            continue
        if X[i]!=X[j]:
            edge.append((i+1,j+1))
print(len(edge))
for line in edge:
    x,y=line
    print(x,y)