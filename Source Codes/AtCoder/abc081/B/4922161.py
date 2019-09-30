N=int(input())
A=list(map(int,input().split()))
flag=False
ans=0
while True:
    for i,j in enumerate(A):
        if j%2!=0:
            print(ans)
            flag=True
            break
        else:
            A[i]=j/2
    ans+=1 
    if flag:
        break