N=int(input())
A1=list(map(int,input().split()))
A2=list(map(int,input().split()))
a=0
for i in range(1,N+1):
    if a<sum(A1[:i])+sum(A2[i-1:]):
        a=sum(A1[:i])+sum(A2[i-1:])
print(a)