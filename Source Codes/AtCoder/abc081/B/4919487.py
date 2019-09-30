#081 shift only
N =int(input())

A=list(map(int,input().split()))
ans = 0
for i in range(5*10**8):
    tmp=0
    for j,k in enumerate(A):
        if k%2 ==0:
            A[j] =k/2
            tmp+=1
    if tmp ==len(A):
        ans+=1
    else:
        print(ans)
        exit()