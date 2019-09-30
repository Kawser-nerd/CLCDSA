N=int(input())
T,A=map(int,input().split())
H=[int(i) for i in input().split()]
ans=0
que=T-0.006*H[0]
for i in range(1,N):
    temp=T-0.006*H[i]
    if abs(A-que)>abs(A-temp):
        que=temp
        ans=i
print(ans+1)