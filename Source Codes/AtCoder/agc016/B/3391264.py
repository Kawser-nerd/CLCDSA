N=int(input())
A=[int(i) for i in input().split()]
M=max(A)
m=min(A)
if M-m>=2:
    print("No")
elif M-m==1:
    x=0
    y=0
    for i in range(N):
        if A[i]==m:
            x+=1
        else:
            y+=1
    if x<M and 2*(M-x)<=y:
        print("Yes")
    else:
        print("No")
else:
    if 2*M<=N or M==N-1:
        print("Yes")
    else:
        print("No")