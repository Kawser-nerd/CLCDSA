N=int(input())
A=[0]+list(map(int,input().split()))+[0]

x=[0]
x[0]=A[0]
for i in range(2,N+3):
    x.append(x[i-2]+abs(A[i-1]-A[i-2]))

for i in range(1,N+1):
    ans=0
    ans+=x[i-1]+abs(A[i-1]-A[i+1])+x[-1]-x[i+1]
    print(ans)