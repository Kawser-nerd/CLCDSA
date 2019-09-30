N,M=map(int,input().split())
x=[0]*(N+1)
y=[0]*(N+1)
for i in range(M):
    a,b=map(int,input().split())
    if a==1:
        x[b]=1
    if b==N:
        y[a]=1
for i in range(N+1):
    if x[i]==1 and y[i]==1:
        print("POSSIBLE")
        break
else:
    print("IMPOSSIBLE")