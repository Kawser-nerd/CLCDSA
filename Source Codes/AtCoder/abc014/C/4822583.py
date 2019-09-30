m=1000001
n=int(input())
ab=[list(map(int, input().split())) for i in range(n)]
a=sorted([abi[0] for abi in ab])
b=sorted([abi[1] for abi in ab])
A=[0]*m
B=[0]*m
Sa=[0]*m
Sb=[0]*m
for i in range(n):
    A[a[i]]+=1
    B[b[i]]+=1
Sa[0]=A[0]
Sb[0]=0
for i in range(1, m):
    Sa[i]=Sa[i-1]+A[i]
    Sb[i]=Sb[i-1]+B[i-1]
ans=0
for i in range(m):
    ans=max(ans, Sa[i]-Sb[i])
print(ans)