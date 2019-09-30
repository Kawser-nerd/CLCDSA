N=int(input())
if N==1:
    print(1)
    exit()
else:
    L=[]
    for i in range(N):
        n=int(input())
        L.append(n)
    
    ans=0
    M="N"
    S=0 
    for i in range(1,N):
        if M=="N":
            if L[i]>L[i-1]:
                M="U"
                S=i-1
        elif M=="U":
            if L[i]>=L[i-1]:
                pass
            else:
                M="D"
        else:
            if L[i]<=L[i-1]:
                pass
            else:
                M="U"
                S=i-1
        if ans<i-S+1:
            ans=i-S+1
    print(min(N,ans))