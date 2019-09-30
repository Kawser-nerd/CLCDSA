import sys
input=sys.stdin.readline
N=int(input())
ans=0
A=sorted([int(input()) for _ in range(N)])
for i in range(N):
    k=0
    for j in range(N):
        if (A[i]%A[j]==0)and(i!=j):
            k+=1
    if k%2==0:
        ans+=(k+2)/(2*k+2)
    else:
        ans+=1/2
print(ans)